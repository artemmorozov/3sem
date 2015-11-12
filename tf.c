#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define n 10

int main()
{
    int fd1[2], fd2[2];
    ssize_t size;
    int result;
    if(pipe(fd1) < 0) 
    {
        printf("Can`t create pipe");
        exit(-1);
    }
    result = fork();
   if(result > 0) 
   {
       int a, b, c;
       scanf("%d%d", &a, &b);
       close(fd1[0]);
       close(fd2[1]);
       size = write(fd1[1] , &a, n);
       size = write(fd1[1] , &b, n);
       close(fd1[1]);
       size = read(fd2[0] , &c , n);
       printf("%d\n", c);
       close(fd1[1]);
       close(fd2[0]);
   }
   else 
   {
       close(fd1[1]);
       close(fd2[0]);
       int a, b, c;
       size = read(fd1[0] , &a , n);
       size = read(fd1[0] , &b , n);
       c = a * b; 
       size = write(fd2[1] , &c, n);
       close(fd1[0]);
       close(fd2[1]);
    }
    
    return 0;
}
