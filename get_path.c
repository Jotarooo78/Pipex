/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:43 by armosnie          #+#    #+#             */
/*   Updated: 2025/03/31 16:14:13 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (join == NULL)
		return (NULL);
	while (s1[i])
	{
		join[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		join[i + j] = s2[j];
		j++;
	}
	join[i + j] = '\0';
	return (join);
}

char *find_path(char *path, char **envp)
{
    int i;
    int j;

    i = 0;   
    while (envp[i])
    {
        j = 0;
        while (envp[i][j] == path[j])
        {
            j++;
            if (!path[j])
                return (&envp[i][j]);
        }
        i++;
    }
    return (NULL);
}

void    get_path(char **argv, char **envp)
{
    char **path;
    int i;
    char *tmp;
    char *cmd_path;

    path = ft_split(find_path("PATH=", envp), ':');
    if (!path)
        return ;
    i = 0;
    while (path[i])
    {
        tmp = ft_strjoin(path[i], "/");
        cmd_path = ft_strjoin(tmp, argv[0]);
        free(tmp);
        if ((access(cmd_path, X_OK)) == 0)
        {
            execve(cmd_path, argv, envp);
            free(cmd_path);
            ft_error("execve error\n");
        }
        free(cmd_path);
        i++;
    }
    free_array(path);
}

int main(int ac, char **av, char **envp)
{
    if (ac > 1)
    {
        get_path(&av[1], envp);
    }
    return (1);
}