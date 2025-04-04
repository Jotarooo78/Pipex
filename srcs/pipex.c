/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/04 20:33:59 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


void    init_variable(int argc, char **argv, char **envp)
{
    s_data *data;

    data->argc = argc;
    data->argv = argv;
    data->envp = envp;
    data->index = 2;
}

void    exec_cmd(s_data *data)
{
    char **cmd_args;
    char *cmd_path;
    
    cmd_args = ft_split(data->argv[data->index], ' ');
    if (data->argv[0] == NULL)
    {
        free_array(cmd_args);
        ft_error("invalid argument\n");
    }
    if (ft_strchr(cmd_args[0], '/') == 1)
        cmd_path = cmd_args[0];
    else
        cmd_path = get_command_path(data->argv[data->index], data->envp);
    if (execve(cmd_path, data->argv[data->index], data->envp) == -1)
    {
        free(cmd_path);
        free_array(cmd_args);
        ft_error("command not found\n");
    }
}

void    child_redirection(s_data *data)
{
    
}

void    pipe_function(s_data *data)
{
    int fd[2];
    pid_t pid;
    
    if (pipe(fd) == -1)
        (ft_error("pipe error\n"));
    if ((pid = fork()) == -1)
        (ft_error("fork error\n"));
    if (pid == 0)
    {
        close(fd[0]);
        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);
        child_redirection(&data);
    }
    else
    {
        close(fd[1]);
        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);
    }
}

void