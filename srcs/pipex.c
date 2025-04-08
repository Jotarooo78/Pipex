/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:19:35 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/08 17:04:03 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// void    open_infile(s_data *data)
// {
//     int fd;
//     printf("infile : %s\n", data->argv[data->index]);
//     fd = open(data->argv[data->index], O_RDONLY);
//     if (fd == -1)
//     {
//         printf("index : %d\n", data->index);
//         ft_error("open infile error");
//         exit(0);
//     }
//     dup2(fd, STDIN_FILENO);
//     close(fd);
// }

// void    open_outfile(s_data *data)
// {
//     int fd;
//     printf("outifle : %s\n", data->argv[data->index]);
//     fd = open(data->argv[data->index], O_WRONLY | O_CREAT | O_TRUNC, 0644);
//     if (fd == -1)
//     {
//         ft_error("open outfile error");
//         exit(0);
//     }
//     dup2(fd, STDOUT_FILENO);
//     close(fd);
// }

// void    setup_child(s_data *data, int *fd)
// {
//     if (data->argv[0] == NULL)
//     {
//         ft_error("invalid argument");
//         exit(0);
//     }
//     else if (data->index - data->begin == 0)
//         open_infile(data);
//     else if (data->index == data->argc - 1)
//         open_outfile(data);
//     exe_my_cmd(data->argv[data->index], data->envp, data);
// }

// pid_t    pipe_function(s_data *data)
// {
//     pid_t pid;
//     int fd[2];
    
//     if (pipe(fd) == -1)
//         ft_error("pipe error");
//     if ((pid = fork()) == -1)
//         (ft_error("fork error"));
//     if (pid == 0)
//     {
//         if (data->index != data->argc - 2)
//         {
//             close(fd[0]);
//             dup2(fd[1], STDOUT_FILENO);
//             close(fd[1]);
//         }  
//         setup_child(data, fd);
//         exit(0);
//     }
//     else
//     {
//         close(fd[1]);
//         dup2(fd[0], STDIN_FILENO);
//         close(fd[0]);
//     }
//     return (pid);
// }

void manage_pids_wait(int argc, char **argv, char **envp)
{
    s_data data;

    if(init_variable(argc, argv, envp,&data) ==false);
    return;//j'ai pas chercher plus loin
    // while (data->index < argc - 1)
    // {
    //     data->pids[data->index] = pipe_function(data);
    //     data->index++;
    // }
    // data->index = 0;
    // while (data->index < argc - 3)
    // {
    //     waitpid(data->pids[data->index],NULL, 0);
    //     data->index++;
    // }
    // free_variable(data);
    // exit(status);
    return;
}
