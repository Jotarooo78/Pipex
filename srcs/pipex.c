/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/09 16:19:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    open_infile(t_data *data, int i, int *pipe_fd)
{
    int fd;

    close(pipe_fd[READ]);
    fd = open(data->infile, O_RDONLY);
    if (fd == -1)
    {
        dup2(pipe_fd[WRITE], STDOUT);
        close(pipe_fd[WRITE]);
        ft_error("infile opening error");
    }
    dup2(fd, STDIN);
    close(fd);
}

void    open_outfile(t_data *data, int i, int *pipe_fd)
{
    int fd;

    close(pipe_fd[READ]);
    fd = open(data->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1)
    {
        dup2(pipe_fd[WRITE], STDOUT);
        close(pipe_fd[WRITE]);
        ft_error("outfile opening error");
    }
    dup2(fd, STDOUT);
    close(fd);
}

void    setup_child(t_data *data, int *pipe_fd, int i)
{
    if (i == 0)
    {
        open_infile(data, i, pipe_fd);
    }
    else if (i == data->n_cmd - 1)
    {
        open_outfile(data, i, pipe_fd);
    }
    exe_my_cmd(data->cmd[i], data->envp, data);
}

bool    call_child(t_data *data, int *pipe_fd, int i)
{
    close(pipe_fd[READ]);
    dup2(pipe_fd[WRITE], STDOUT);
    close(pipe_fd[WRITE]);
    setup_child(data, pipe_fd, i);
    exit(0);
}

void    call_parent(t_data *data, int *pipe_fd)
{
    close(pipe_fd[WRITE]);
    dup2(pipe_fd[READ], STDIN);
    close(pipe_fd[READ]);
}

void    pipe_function(t_data *data)
{
    pid_t pid;
    int i;
    int pipe_fd[2];
    
    i = 0;
    while (data->cmd[i])
    {
        if (pipe(pipe_fd) == -1)
            ft_error("pipe error");
        pid = fork();
        if (pid == -1)
            (ft_error("fork error"));
        if (pid == 0)
            call_child(data, pipe_fd, i);
        else
            call_parent(data, pipe_fd);
        i++;
        wait(NULL);
    }
}

void manage_pids_wait(int argc, char **argv, char **envp)
{
    t_data data;
    
    if (init_variable(argc, argv, envp,&data) == false)
        return;
    pipe_function(&data);
    exit(0);
    return;
}
