/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:29:41 by marvin            #+#    #+#             */
/*   Updated: 2025/04/08 17:07:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

bool    init_variable(int argc, char **argv, char **envp,s_data *data)
{
    printf("BEFORE:\n;");
    for(int i = 0;argv[i];i++)
    {
        printf("%s\n",argv[i]);
        i++;
    }
    data->pids = malloc(sizeof(pid_t) * argc - 3);
    if (data->pids == NULL)
        return (false); 
    data->outfile = argv[argc-1];
    data->infile = argv[1];
    data->cmd = argv + 2;
    data->n_cmd = argc -3;
    data->envp = envp;
    for(int i = 0;i <= data->n_cmd;i++)
    {
        printf("%s\n",data->cmd[i]);
        i++;
    }
    printf("infile:%s\noutfile:%s\n",data->infile,data->outfile);
    return (true);
}

int main(int argc, char **argv, char **envp)
{
    if (argc != 4)
    {
        manage_pids_wait(argc, argv, envp);
    }
    return (1);
}