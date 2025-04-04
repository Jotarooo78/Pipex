/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armosnie <armosnie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:43 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/04 17:03:11 by armosnie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	*join_path(char *path, char *cut_cmd)
{
    char *add_slash;
    char *full_path;

    add_slash = ft_strjoin(path, "/");
    if (add_slash == NULL)
        return (NULL);
    full_path = ft_strjoin(add_slash, cut_cmd);
    return (full_path);
}

char    **get_path(char **envp)
{
    char **path;
    char *target_path;
    int i;

    i = 0;
    while(envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            target_path = envp[i];
        }
        i++;
    }
    if (target_path == NULL)
        ft_error("no path found\n");
    path = ft_split(target_path, ':');
    if (path == NULL)
        ft_error("path error\n");
    return (path);
}

char   *try_access(char **path, char *cut_cmd)
{
    char *full_path;
    int i;
    
    i = 0;    
    while (path[i])
    {
        full_path = join_path(path[i], cut_cmd);
        if (full_path == NULL)
            return (NULL);
        if ((access(full_path, F_OK | X_OK)) == 0)
            return (full_path);
        free(full_path);
        i++;
    }
    return (NULL);
}

char    *get_command_path(char *cmd, char **envp)
{
    char **cut_cmd;
    char **path;
    char *cmd_path;
    
    path = get_path(envp);
    cut_cmd = ft_split(cmd, ' ');
    if (cut_cmd == NULL)
    {
        free_array(path);
        return (NULL);        
    }
    cmd_path = try_access(path, cut_cmd[0]);
    free_array(path);
    free_array(cut_cmd);
    return (cmd_path);
}