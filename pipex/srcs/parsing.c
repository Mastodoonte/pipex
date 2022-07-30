/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:31:35 by florianma         #+#    #+#             */
/*   Updated: 2021/09/11 17:30:05 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*parsing_path(char **env, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	while (env[i])
	{
		tmp = ft_strjoin(env[i], "/");
		path = ft_strjoin(tmp, cmd);
		free_str(&tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free_str(&path);
		i++;
	}
	return (NULL);
}

void	*get_path(char **env, char **cmd)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			paths = ft_split(&env[i][5], ':');
		i++;
	}
	path = parsing_path(paths, *cmd);
	free_split(paths);
	return (path);
}
