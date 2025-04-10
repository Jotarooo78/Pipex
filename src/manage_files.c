/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_files.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 19:02:16 by marvin            #+#    #+#             */
/*   Updated: 2025/04/10 19:02:16 by marvin           ###   ########.fr       */
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