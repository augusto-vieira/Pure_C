#include <stdio.h>
#include <pqueue.h>
#include <string.h>
#include <signal.h>

static int quit = 0;

void quit_handler(int sig_num)
{
  (void)sig_num;
  quit = 1;
}

queue_t message;

void analize_id(queue_t *m);

int main(int argc, char *argv[])
{
    int msgid;

    //register quit_handler 
    signal(SIGINT, quit_handler);
    msgid = queue_init("progfile");
    
    while(!quit)
    {
      printf("waiting message...\n");
      memset(message.b, 0, sizeof(message.b));
      queue_recv(msgid, &message, 2);
      analize_id(&message);
    }
    printf("Finished.\n");

    queue_delete(msgid);
    return 0;
}

void analize_id(queue_t *m)
{
  if(m == NULL)
    return ;

  switch(m->id)
  {
    case 1:
      printf("English : ");
      break;

    case 2:
      printf("Deutsch: ");
      break;

    default:
      return ;

  }
  
  printf("%s\n", m->b);
  return ;
}
