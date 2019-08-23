#ifndef __QUEUE_H
#define __QUEUE_H

#define _1K   1024
#define _4K   ( _1K * 4)

#define DATA_BUFFER_LEN 

typedef struct queue_st{
  long int queue_type;
  char data_buffer[_4K];
}queue_st;

int queue_init(void);
int queue_send(const queue_st *data, const int buffer_size);
int queue_recv(queue_st *data, const int buffer_size);
int queue_deinit(void);
#endif
