#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

#include <sys/msg.h>

#include <queue.h>

typedef struct queue_context{
  int msgid;
  long int msg_to_receive;
}queue_context_st;

queue_context_st queue_ctx = {
  .msgid = -1,
  .msg_to_receive = 0
};

int queue_init(void)
{
  queue_ctx.msgid = msgget((key_t) 1234, 0666 | IPC_CREAT);
  if(queue_ctx.msgid == -1){
    fprintf(stderr, "Queue Init error: %d\n", errno);
    return EXIT_FAILURE;
  }
  return EXIT_SUCCESS;
}

int queue_send(queue_st *data, const int buffer_size)
{
  int ret = -1;
  if(queue_ctx.msgid == -1){
    fprintf(stderr, "Queue not initialize.\n");
    return EXIT_FAILURE;
  }

  data->queue_type = 1;
  ret = msgsnd(queue_ctx.msgid, (void *)data, buffer_size, 0);
  if(ret == -1){
    fprintf(stderr, "queue send error\n");
    return EXIT_FAILURE;
  }

  return EXIT_SUCCESS;
}

int queue_recv(queue_st *data, const int buffer_size)
{
  int ret = -1;

  if(queue_ctx.msgid == -1){
    fprintf(stderr, "Queue not initialize.\n");
    return (EXIT_FAILURE);
  }

  ret = msgrcv(queue_ctx.msgid, (void *)data, buffer_size, queue_ctx.msg_to_receive, 0);
  if(ret == -1){
    fprintf(stderr, "queue_recv error: %d\n", errno);
    return (EXIT_FAILURE);
  }

  return EXIT_SUCCESS;
}
int queue_deinit(void)
{
  int ret = -1;
  if(queue_ctx.msgid == -1){
    fprintf(stderr, "Queue not initialize.\n");
    return(EXIT_FAILURE);
  }

  ret = msgctl(queue_ctx.msgid, IPC_RMID, 0);
  if(ret == -1){
    fprintf(stderr, "queue deinit error\n");
    return (EXIT_FAILURE);
  }
  return (EXIT_SUCCESS);
}

