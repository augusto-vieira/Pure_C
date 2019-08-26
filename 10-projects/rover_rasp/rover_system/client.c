
// Write CPP code here 
#include <netdb.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 

#define MAX 4096 
#define PORT 8080 
#define SA struct sockaddr 

typedef struct client_st{
  int id;
  char buff[512];
}client_st;

void func(int sockfd) 
{ 
  client_st cl;
  char server_b[MAX];

    int n; 
    for (;;) { 
        bzero(cl.buff, sizeof(cl.buff)); 
        bzero(server_b, sizeof(server_b)); 

        printf("Enter a id: ");
        scanf("%d", &cl.id);

        printf("Enter the string : "); 
        n = 0; 
        while ((cl.buff[n++] = getchar()) != '\n') 
            ; 

        memcpy(server_b, &cl, sizeof(cl)) ;

        write(sockfd, server_b, sizeof(server_b)); 
        if ((strncmp(cl.buff, "exit", 4)) == 0) { 
            printf("Client Exit...\n"); 
            break; 
        } 
    } 
} 
  
int main() 
{ 
    int sockfd, connfd; 
    struct sockaddr_in servaddr, cli; 

    char server_ip[100];

//    printf("Enter a server ip: ");
 //   gets(server_ip);
    // socket create and varification 
    sockfd = socket(AF_INET, SOCK_STREAM, 0); 
    if (sockfd == -1) { 
        printf("socket creation failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully created..\n"); 
    bzero(&servaddr, sizeof(servaddr)); 
  
    // assign IP, PORT 
    servaddr.sin_family = AF_INET; 
    //servaddr.sin_addr.s_addr = inet_addr(server_ip); 
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
    servaddr.sin_port = htons(PORT); 
  
    // connect the client socket to server socket 
    if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
        printf("connection with the server failed...\n"); 
        exit(0); 
    } 
    else
        printf("connected to the server..\n"); 
  
    // function for chat 
    func(sockfd); 
  
    // close the socket 
    close(sockfd); 
} 
