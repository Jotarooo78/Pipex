/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:47:56 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/01 15:20:42 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <stdio.h>

# define STDIN 0
# define STDOUT 1
# define  EXIT_FAILURE 1
# define  EXIT_SUCCESS 0

typedef struct s_struct
{
    int pathnbr;
       
}   s_struct;

// parcing functions

char	**ft_split(const char *s, char c);
void	free_array(char **split);
void    get_path(char **argv, char **envp);
int ft_error(char *str);


#endif