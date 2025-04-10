/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:29:41 by marvin            #+#    #+#             */
/*   Updated: 2025/04/09 16:07:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool    init_variable(int argc, char **argv, char **envp, t_data *data)
{
    data->outfile = argv[argc-1];
    data->infile = argv[1];
    data->cmd = argv + 2;
    data->cmd[argc - 3] = NULL;
    data->n_cmd = argc - 3;
    data->envp = envp;
    return (true);
}

int main(int argc, char **argv, char **envp)
{
    if (argc >= 4)
    {
        manage_pids_wait(argc, argv, envp);
    }
    return (1);
}