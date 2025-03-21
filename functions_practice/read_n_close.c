#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) 
{
    char buf[BUFFER_SIZE];
    int size_read = 0;
    if (argc < 2)
    {
        printf("opening error");
        return (1);
    }
    int fd = open(argv[1], O_RDONLY);
    if (fd == -1)
    {
        printf("textfile's missing");
        return (1);
    }
    while ((size_read = read(fd, buf, BUFFER_SIZE)) != 0)
    {
        write(1, buf, size_read);
    }
    close(fd);
    return (0);
}