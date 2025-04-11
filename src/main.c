/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:29:41 by marvin            #+#    #+#             */
/*   Updated: 2025/04/11 19:06:24 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool    init_variable(int argc, char **argv, char **envp, t_data *data)
{
    int i;

    i = 0;
    data->outfile = argv[argc - 1];
    data->infile = argv[1];
    data->cmd = argv + 2;
    data->cmd[argc - 3] = NULL;
    data->n_cmd = argc - 3;
    data->envp = envp;
    while (i < data->n_cmd)
    {
        if (data->cmd[i][0] == '\0')
        {
            ft_error("not enough error", 1);
            return (false);
        }
        i++;
    }
    return (true);
}

int main(int argc, char **argv, char **envp)
{
    if (argc >= 5)
    {
        t_data data;
        if (init_variable(argc, argv, envp, &data) == false)
            return (1);
        pipe_function(&data);
        return (0);
    }
    return (1);
}