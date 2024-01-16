#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <limits.h>
#include <time.h>

int main()
{
    int run=10, fd[2]; 
    pipe(fd); 
    srand(time(0)); 
    char ch, x='x', o='o'; 

    if(!fork())
    {
        close(fd[0]);

        while(run)
        {
            sleep(1+rand()%6); write(fd[1],&x,1);
        }
        exit(0); //This exit doesn't happen
    }

    if(!fork())
    {
        close(fd[0]);

        while(run)
        {
            sleep(1+rand()%3); write(fd[1],&o,1);
        }

        exit(0); //This exit doesn't happen
    }

    close(fd[1]);
    while(run--)
    {
        read(fd[0],&ch,1);
        printf("%d %c\n",run,ch);
        sleep(1);
    }

    // close(fd[0]); //closing this file descriptor results in that the program can exit
    wait(0);
    wait(0);
    exit(0);

}