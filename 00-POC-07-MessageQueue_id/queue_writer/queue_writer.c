#include <stdio.h>
#include <pqueue.h>
#include <string.h>

queue_t message1;
queue_t message2;

int main(int argc, char *argv[])
{
    int msgid;

    msgid = queue_init("progfile");
    
    message1.id= 1;
    strcpy(message1.b, "Hello World");
    queue_send(msgid, &message1);

    message2.id= 2;
    strcpy(message2.b, "Hallo Welt");
    queue_send(msgid, &message2);

    return 0;
}

