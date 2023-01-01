#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    int shmid;
    char *mesg;
    if((shmid=shmget(10,1024,0))==-1)
    {
        perror("shmget");
        exit(1);
    }
    mesg=shmat(shmid,0,0);
    printf("Data written in the shared memory is : %s\n",mesg);
    getchar();
    shmdt(mesg);
    return 0;
}
