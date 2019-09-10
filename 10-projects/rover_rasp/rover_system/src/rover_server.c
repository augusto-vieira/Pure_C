#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>
#include <sys/socket.h> 
#include <sys/types.h> 
#include <queue.h>
#include <log.h>

#define MAX 4096 
#define PORT 8080 
#define SA struct sockaddr 

#define ROVER_SERVER  "ROVER_SERVER"

typedef struct temp
{
  int id;
  int status;
  char data[512];
}temp_t;
  
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
    temp_t t;
    queue_st queue;
    char buff[MAX]; 
    int ret; 
    // infinite loop for chat 

    for (;;) { 
      bzero(buff, MAX); 

      // read the message from client and copy it in buffer 
      ret = read(sockfd, buff, sizeof(buff)); 
      if(ret >= 0){

        memcpy(&t, buff, sizeof(t));
        if(strncmp(t.data, "quit", 4) == 0){
          close(sockfd);
          return ;
        }

        if(strlen(t.data) <= 0){
          continue;
        }

        log(ROVER_SERVER, t.data);

        memcpy(queue.data_buffer, buff, sizeof(buff));
        ret = queue_send(&queue, sizeof(queue.data_buffer));
        if(ret != 0){
          log(ROVER_SERVER, "Error Queue Send.");
        }
      }
    } 
} 
  
// Driver function 
int main() 
{ 
    int sockfd, connfd, len; 
    struct sockaddr_in servaddr, cli; 

    if(queue_init() != 0){
      log(ROVER_SERVER, "Queue init failed");
      exit(1);
    }
    // socket create and verification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
      log(ROVER_SERVER, "Socket creation failed.");
      exit(1); 
    } 
    else{
      log(ROVER_SERVER, "Socket successfully created");
    }
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
      log(ROVER_SERVER, "Bind failed.");
      exit(1); 
    } 
    else{
      log(ROVER_SERVER, "Server successfully binded.");
    }

    while(1)
    {  
      // Now server is ready to listen and verification 
      if ((listen(sockfd, 1)) != 0) { 
      log(ROVER_SERVER, "Listen failed.");
        exit(1); 
      } 
      else{
        log(ROVER_SERVER, "Server listening.");
      }
      len = sizeof(cli); 
    
      // Accept the data packet from client and verification 
      connfd = accept(sockfd, (SA*)&cli, &len); 
      if (connfd < 0) { 
        log(ROVER_SERVER, "Server accept failed.");
        exit(1); 
      } 
      else{
        log(ROVER_SERVER, "Server accept client.");
      }
    
      // Function for chatting between client and server 
      func(connfd); 
      log(ROVER_SERVER, "Client Disconnected");
    }  
    // After chatting close the socket 
    queue_deinit();
    close(sockfd); 
} 

  
