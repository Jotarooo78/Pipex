/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 17:54:43 by armosnie          #+#    #+#             */
/*   Updated: 2025/04/05 22:22:25 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char    **get_path(char **envp)
{
    char **path;
    char *target_path;
    int i;

    target_path = NULL;
    i = 0;
    while (envp[i])
    {
        if (ft_strncmp(envp[i], "PATH=", 5) == 0)
        {
            target_path = envp[i] + 5;
            break ;
        }
        i++;
    }
    if (target_path == NULL)
        ft_error("path not found");
    path = ft_split(target_path, ':');
    if (path == NULL)
        return (NULL);
    return (path);
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

char    *try_access(char **path, char *cmd_path)
{
    char *full_cmd_path;
    int i;

    i = 0;
    while (path[i])
    {
        full_cmd_path = join_slash(path[i], cmd_path);
        if (full_cmd_path == NULL)
            return (NULL);
        if (access(full_cmd_path, F_OK | X_OK) == 0)
            return (full_cmd_path);
        free(full_cmd_path);
        i++;
    }
    return (NULL);
}


char    *get_command_line(char *cmd, char **envp)
{
    char **path;
    char **cmd_cut;
    char *cmd_path;
 
    cmd_cut = ft_split(cmd, ' ');
    if (cmd_cut == NULL)
        return (NULL);
    path = get_path(envp);
    if (path == NULL)
    {
        free_array(cmd_cut);
        return (NULL);
    }
    cmd_path = try_access(path, cmd_cut[0]);
    free_array(path);
    free(cmd_cut);
    if (cmd_path == NULL)
        ft_error("access error \n");
    return (cmd_path);
}

int main(int ac, char **av, char **envp)
{
    if (ac > 1)
    {
        printf("get_command_line : %s\n", get_command_line(av[1], envp));
    }
    return (0);
}