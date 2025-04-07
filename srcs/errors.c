
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 11:43:25 by armosnie          #+#    #+#             */
/*   Updated: 2025/03/20 11:48:14 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void    free_variable(s_data *data)
{
    int i;

    i = 0;
    if (data == NULL)
        return ;
    if (data->pids != NULL)
        free(data->pids);
    free(data);
}

void    free_array(char **array)
{
    int i;

    i = 0;
    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}

int ft_error(char *str)
{
    perror(str);
}