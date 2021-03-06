#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

#define smtp_domain_name "";

int connectToServer(const char *server_address);

int main(int argc, char *argv[])
{
  return EXIT_SUCCESS;
}


int connectToServer(const char *server_address)
{
  int socket_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_IP);
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_port = htons(25);
  if(inet_pton(AF_INET, getIpAddress(server_address), addr.sin_addr) == 1)
  {
    connect(socket_fd, &addr, sizeof(addr));
  }

  return socket_fd;
}

const char *getIpAddress(char const *target_domain)
{
  const char *target_ip;
  struct in_addr *host_address;
  struct hostent *raw_list = gethostbyname(target_domain);
  int i = 0;

  for( i; raw_list->h_addr_list[i] != 0; i++)
  {
    host_address = raw_list->h_addr_list[i];
    target_ip = inet_ntoa(host_address);
  }

  return target_ip;
}
