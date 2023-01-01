#include<stdio.h>
#include<string.h>
#include<unistd.h>

void main()
{
	size_t len;
	int msg_len=0;
	char buf[100];

	strncpy(buf,"This is writing to screen using write() system call instead of printf library call\n",99);
	msg_len=strlen(buf);
	len=write(1,buf,msg_len);
}
