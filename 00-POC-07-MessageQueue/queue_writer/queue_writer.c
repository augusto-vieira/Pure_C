#include <stdio.h>
#include <pqueue.h>

queue_t message;

int main(int argc, char *argv[])
{
    int msgid;

    msgid = queue_init("progfile");
    message.id= 1;

    printf("Write Data: ");
    fgets(message.b, sizeof(message.b), stdin);

    queue_send(msgid, &message);

    printf("Data send is : %s \n", message.b);

    return 0;
}

