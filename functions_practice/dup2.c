#include <unistd.h>

int duplicate_fd(char *str)
{
    int fd[2];
    
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        duplicate_fd(av[1]);
    }
}