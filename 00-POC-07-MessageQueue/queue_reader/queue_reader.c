#include <stdio.h>
#include <pqueue.h>
#include <string.h>

queue_t message;

int main(int argc, char *argv[])
{
    int msgid;

    msgid = queue_init("progfile");
    
    while(strncmp("quit", message.b, 4) != 0)
    {
      printf("waiting message...\n");
      memset(message.b, 0, sizeof(message.b));
      queue_recv(msgid, &message, 1);
      printf("Data received is %s \n", message.b);
    }

//    msgctl (msgid, IPC_RMID, NULL);

    return 0;
}
