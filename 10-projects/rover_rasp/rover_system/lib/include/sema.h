#ifndef __SEMA_H
#define __SEMA_H

int semaphore_init(void);
int semaphore_lock(void);
int semaphore_unlock(void);
int semaphore_delete(void);

#endif

