/*
 ============================================================================
 Name        : Shared Memory read
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	key_t key = ftok("shmfile", 65);

	//shmget returns an identifier in shmid
	int shmid = shmget(key, 1024, 0666 | IPC_CREAT);

	//shmat to attach to shared memory
	char *str = (char *) shmat(shmid, (void *)0, 0);

	printf("Data read from memory: %s\n", str);

	shmdt(str);

	shmctl(shmid, IPC_RMID, NULL);

	return EXIT_SUCCESS;
}

