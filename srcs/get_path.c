/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:43 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/01 17:05:34 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*ft_strjoin(char *path, char *cmd)
{
	char	*join;
	int		i;
	int		j;

	i = 0;
	j = 0;
	join = malloc(sizeof(char) * (ft_strlen(path) + ft_strlen(cmd) + 1));
	if (join == NULL)
		return (NULL);
	while (path[i])
	{
		join[i] = path[i];
		i++;
	}
	while (cmd[j])
	{
		join[i + j] = cmd[j];
		j++;
	}
	return (join);
}

char    **get_path(char **argv, char **envp)
{
    char **path;
    char *target_path;
    int i;

    i = 0;
    while(envp[i])
    {
        if (ft_strncmp("PATH=", envp[i], 5))
        {
            target_path = envp[i] + 5;
        }
        i++;
    }
    if (target_path == NULL)
        ft_error("no path found\n");
    path = ft_split(target_path, ':');
    if (path == NULL)
        return (EXIT_FAILURE);
    return (path);
}

char    **get_argv_splited(char **argv, char **envp)
{
    int i;

    i = 1;
    while (argv[i + 1] != NULL)
    {
        argv[i] = ft_split(argv[i], ' ');
        if (argv[i] == NULL)
            ft_error("argv split error\n");
        i++;
    }
    return (argv);
}

void   exec_cmd(char **argv, char **envp)
{
    char **path;
    char *tmp;
    char *cmd_path;
    int i;

    i = 0;
    path = get_path(argv, envp);
    argv = get_argv_splited(argv, envp);
    
    while (path[i])
    {
        tmp = ft_strjoin(path[i], '/');
        cmd_path = ft_strjoin(tmp, argv[]);
    }
}

char    *add_slash(char *path, char *cmd_path)

int main(int ac, char **av, char **envp)
{
    if (ac > 1)
    {
        get_path(&av[1], envp);
    }
    return (1);
}

// void    get_path(char **argv, char **envp)
// {
//     char **path;
//     int i;
//     char *tmp;
//     char *cmd_path;

//     path = ft_split(find_path("PATH=", envp), ':');

//     i = 0;
//     while (path[i])
//     {
//         tmp = ft_strjoin(path[i], "/");
//         cmd_path = ft_strjoin(tmp, argv[0]);
//         free(tmp);
//         if ((access(cmd_path, X_OK)) == 0)
//         {
//             execve(cmd_path, argv, envp);
//             free(cmd_path);
//             ft_error("execve error\n");
//         }
//         free(cmd_path);
//         i++;
//     }
//     free_array(path);
// }