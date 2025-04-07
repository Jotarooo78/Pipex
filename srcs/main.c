/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:29:41 by marvin            #+#    #+#             */
/*   Updated: 2025/04/07 16:30:04 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

s_data    *init_variable(int argc, char **argv, char **envp)
{
    s_data *data;
    int nb_cmd;

    nb_cmd = argc - 3;
    data = malloc(sizeof(s_data));
    if (data == NULL)
        return (NULL);
    pids = malloc(sizeof(pid_t) * nb_cmd);
    if (pids == NULL)
        return (NULL);
    data->argc = argc;
    data->argv = argv;
    data->envp = envp;
    data->index = 2;
    return (data);
}

int main(int argc, char **argv, char **envp)
{
    if (argc != 5)
    {
        open_files();
        pipe_function(fd, data);
    }
}