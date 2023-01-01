#include<stdio.h>
#include<stdlib.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main()
{
    int shmid;
    char *mesg;
    if((shmid=shmget(10,1024,0666|IPC_CREAT))==-1){
        perror("shmget");
        exit(1);
    }
    mesg=shmat(shmid,0,0);
    printf("Enter the data you want to write into shared memory\n");
    fgets(mesg,1024,stdin);
    printf("Data successfully written\n");

    getchar();
    shmdt(mesg);
    return 0;
}
