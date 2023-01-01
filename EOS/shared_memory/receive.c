#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/shm.h>

int main()
{
    void *shared_memory;
    char buff[100];
    int shmid;
    shmid=shmget((key_t)1122,1024,0666);
    printf("key of shared memory is %d\n",shmid);
    shared_memory=shmat(shmid,NULL,0);
    printf("Processed attached at %p\n",shared_memory);
    printf("Data read from shared memory is : %s\n",(char *)shared_memory);
}