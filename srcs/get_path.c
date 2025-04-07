/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:43 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/07 11:40:19 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char    **get_path(char **envp)
{
    char **path;
    int i;

    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            path = ft_split(envp[i] + 5, ':');
            if (path == NULL)
                return (NULL);
            return (path);
        }
        i++;
    }
    ft_error("path not found"); 
    return (NULL);
}

char    *join_slash(char *path, char *cmd_cut)
{
    char *full_path;
    char *path_slash;

    path_slash = ft_strjoin(path, "/");
    if (path_slash == NULL)
        return (NULL);
    full_path = ft_strjoin(path_slash, cmd_cut);
    if (full_path == NULL)
        return (NULL);
    free(path_slash);
    return (full_path);
}

int    exec(char **path, char *cmd_cut, char **cmd, char **envp)
{
    char *full_path;
    int i;

    i = 0;
    while (path[i])
    {
        full_path = join_slash(path[i], cmd_cut);
        if (full_path == NULL)
            return (0);
        if (access(full_path, F_OK | X_OK) == 0)
            execve(full_path, cmd, envp);
        free(full_path);
        i++;
    }
    return (1);
}


void    exe_my_cmd(char *cmd, char **envp)
{
    char **path;
    char **cmd_cut;
 
    cmd_cut = ft_split(cmd, ' ');
    if (cmd_cut == NULL)
        return ;
    path = get_path(envp);
    if (path == NULL)
    {
        free_array(cmd_cut);
        return ;
    }
    exec(path, cmd_cut[0], cmd_cut, envp);
    free_array(path);
    free_array(cmd_cut);
    ft_error("exec error");
}

int main(int ac, char **av, char **envp)
{
    if (ac > 1)
    {
        exe_my_cmd(av[1], envp);
    }
    return (0);
}