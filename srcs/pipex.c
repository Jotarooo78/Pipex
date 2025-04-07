/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/07 16:50:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    exec_cmd(s_data *data)
{    
    if (data->argv[0] == NULL)
    {
        ft_error("invalid argument");
    }
    exe_my_cmd(data->argv[data->index], data->envp)
}

int    open_files(int argc, char **argv, int option)
{
    if (option == 0)
    {
        int fdoutfile[2];
        fdoutfile = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fdoutfile == -1)
            ft_error("open outfile error");
        return (fdoutfile[2]);
    }
    else if (option == 1)
    {
        int fdinfile[2];
        fdinfile = open(argv[1], O_RDONLY);
        if (fdinfile == -1)
            ft_error("open infile error");
        return (fdinfile[2]);
    }
    return (1);
}

void    setup_child(s_data *data)
{
    if 
}

pid_t    pipe_function(s_data *data)
{
    pid_t pid;
    int fd[2];
    
    if (pipe(fd) == -1)
        (ft_error("pipe error"));
    if ((pid = fork()) == -1)
        (ft_error("fork error"));
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        setup_child(data);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
    }
    return (pid);
}

char cmd_loop(s_data *data, char **argv, char **envp)
{
    s_data *data;

    data = init_variable(argc, argv, envp);
    while (data->index < ac - 3)
    {
        data->pids[data->index] = pipe_function(data);
        data->index++;
    }
}