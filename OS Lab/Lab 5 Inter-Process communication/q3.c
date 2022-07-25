#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main()
{
   int fd[2],n;
   char buff[100];
   int p;
   pipe(fd);
   p=fork();
    if(p>0)
    {
    printf("Passing value to the child\n");
    write(fd[1],"hello world\n",15);
    }
    else
    {
    printf("Child received data\n");
    n=read(fd[0],buff,100);
    write(1,buff,n);
    }
return 0;
}