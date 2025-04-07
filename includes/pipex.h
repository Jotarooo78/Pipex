/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/07 16:11:02 by marvin           ###   ########.fr       */
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

typedef struct s_data
{
    pid_t   *pid;
    int index;
    char **envp;
    char **argv;
    int argc;
    
}   s_data;

// parcing functions

s_data    *init_variable(int argc, char **argv, char **envp);
void	free_array(char **split);
int ft_error(char *str);
void    pipe_function(int fd[2], s_data *data);
char    *get_command_path(char *cmd, char **envp);


#endif