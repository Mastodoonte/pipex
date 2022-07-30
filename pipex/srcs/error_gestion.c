/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_gestion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:33:27 by florianma         #+#    #+#             */
/*   Updated: 2021/09/11 16:33:45 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	inexistant_error_file(void)
{
	ft_putendl_fd("Error\ninfile does not exist\n", 2);
	exit(EXIT_FAILURE);
}

void	none_valid_command(char **cmd, char *path)
{
	ft_putendl_fd("command not found: ", 2);
	ft_putendl_fd(cmd[0], 2);
	free_split(cmd);
	if (path)
		free_str(&path);
	exit(EXIT_FAILURE);
}
