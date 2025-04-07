/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/07 11:38:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include "../libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdbool.h>

# define  EXIT_FAILURE 1
# define  EXIT_SUCCESS 0

typedef struct s_data
{
    int index;
    char **envp;
    char **argv;
    int argc;
    char *infile;
    char *outfile;
    
}   s_data;

// parcing functions

char	**ft_split(const char *s, char c);
void	free_array(char **split);
int ft_error(char *str);
char    *get_command_path(char *cmd, char **envp);


#endif