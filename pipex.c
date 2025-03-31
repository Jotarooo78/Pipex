/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/03/31 16:31:38 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"


void    pipex(int argc, char **argv, char **envp)
{
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1)
        return (ft_error("pipe error\n"));
    if ((pid = fork()) == -1)
        return (ft_error("fork error\n"));
    else if (pid == 0)
    {
        close(fd[0]);
        get_path(&argv[1], envp);
        
    }

}


int main(int argc, char **argv, char **envp)
{
    int i;

    i = 0;
    (void)argc;
    (void)argv;
    while (envp[i] && ft_strcmp("PATH", envp[i]) != 0)
    {
        printf("%s\n", envp[i]);
        i++;
    }
}