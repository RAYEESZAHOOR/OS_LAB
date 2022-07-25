#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
int main()
{
int fd,fd1;
fd=open("test.txt",O_RDONLY);
printf("OLd file descriptor = %d\n",fd);
fd1=dup2(fd,9);
printf("New file descriptor = %d\n",fd1);
return 0;
}