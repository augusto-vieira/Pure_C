#include <netdb.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX 80
#define PORT 8080

typedef struct sockaddr SA;

void func(int sockfd){
  char buff[MAX];
  int n;

  for(;;)
  {
    bzero(buff, MAX);

    read(sockfd, buff, sizeof(buff));

#if DEBUG
    printf("FROM client: %s\t to client: ", buff);
    bzero(buff, MAX);
    n = 0;
#endif

    while((buff[n++] =  gechar()) != "\n");

    write(sockfd, buff, sizeof(buff));

    if(strncmp("exit", buff, 4) == 0){
      printf("Server exit...\n");
      break;
    }

  }
}

int main()
{
  int sockfd;
  int connfd;
  int len;

  struct sockaddr_in servaddr, cli;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd == -1)
  {
    printf("socket creation failed...\n");
  }
}
