/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/09 16:02:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdbool.h>

#define STDIN 0
#define STDOUT 1 
#define STDERR 2
#define READ 0 
#define WRITE 1

typedef struct s_data
{
    int     n_cmd;
    char    **cmd;
    char    **envp;
    char    *infile;
    char    *outfile;
    
}   t_data;

// parcing functions

bool    init_variable(int argc, char **argv, char **envp, t_data *data);
void	free_array(char **split);
void ft_error(char *str);
void    pipe_function(t_data *data);
void    exe_my_cmd(char *cmd, char **envp, t_data *data);
void manage_pids_wait(int argc, char **argv, char **envp);


#endif