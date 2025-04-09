/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/09 13:43:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    open_infile(t_data *data, int index, int *pipe_fd)
{
    if (index == 0)
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
}

void    open_outfile(t_data *data, int index, int *pipe_fd)
{
    if (index == 0)
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
}

void    setup_child(t_data *data, int *pipe_fd, int index)
{
    if (index == 0)
        open_infile(data, index, pipe_fd);
    else if (index > data->n_cmd)
        open_outfile(data, index, pipe_fd);
    exe_my_cmd(data->cmd[index], data->envp, data);
}

void    pipe_function(t_data *data, int index)
{
    pid_t pid;
    int pipe_fd[2];
    
    if (pipe(pipe_fd) == -1)
        ft_error("pipe error");
    if ((pid = fork()) == -1)
        (ft_error("fork error"));
    if (pid == 0)
    {
        if (index != data->n_cmd)
        {
            close(pipe_fd[READ]);
            dup2(pipe_fd[WRITE], STDOUT);
            close(pipe_fd[WRITE]);
        }
        setup_child(data, pipe_fd, index);
        exit(0);
    }
    else
    {
        close(pipe_fd[WRITE]);
        dup2(pipe_fd[READ], STDIN);
        close(pipe_fd[READ]);
    }
}

void manage_pids_wait(int argc, char **argv, char **envp)
{
    t_data data;
    int status;
    int i;

    i = 0;
    if (init_variable(argc, argv, envp,&data) == false)
        return;
    while (i < data.n_cmd)
    {
        pipe_function(&data, i);
        wait(&status);
        i++;
    }
    exit(0);
    return;
}
