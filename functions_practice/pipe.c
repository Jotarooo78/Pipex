#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main()
{
    char buf[BUFFER_SIZE];
    int size_read = 0;
    int fd[2];
    pid_t pid;

    if (pipe(pid) == -1)
    {
        perror("Erreur de fork");
        return (1);
    }
    pid = fork();
    if (pid < 0)
    {
        perror("pid error");
        return (1);
    }
    if (pid == 0)
    {
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));
        close(fd[0]);
    }
    if (fd == -1)
    {
        write(2, "fd error\n", 10);
        return (1);
    }
    else
    {
        close(fd[0]);
        write(fd[1], "", sizeof(buf));
        close(fd[1]);
    }
}