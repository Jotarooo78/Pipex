/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/08 17:00:48 by marvin           ###   ########.fr       */
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

# define  EXIT_FAILURE 1
# define  EXIT_SUCCESS 0

#define STDIN 0
#define STDOUT 1 
#define STDERR 2
#define READ 0 
#define WRITE 1

// typedef struct s_data
// {
//     pid_t   *pids;
//     int index;
//     int begin;
//     char **envp;
//     char **argv;
//     int argc;
    
// }   s_data;

typedef struct s_data
{
    pid_t   *pids;
    int n_cmd;
    char **cmd;
    char **envp;
    char* infile;
    char* outfile;
}   s_data;

// parcing functions

bool    init_variable(int argc, char **argv, char **envp,s_data *data);
void	free_array(char **split);
void    free_variable(s_data *data);
void ft_error(char *str);
pid_t    pipe_function(s_data *data);
void    exe_my_cmd(char *cmd, char **envp, s_data *data);
char    *get_command_path(char *cmd, char **envp);
void manage_pids_wait(int argc, char **argv, char **envp);


#endif