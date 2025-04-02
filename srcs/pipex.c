/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/02 19:12:21 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void    pipex(int argc, char **argv, char **envp)
{
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1)
        (ft_error("pipe error\n"));
    if ((pid = fork()) == -1)
        (ft_error("fork error\n"));
    else if (pid == 0)
    {
        close(fd[0]);
        
    }

}