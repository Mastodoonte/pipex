/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 13:55:28 by florianma         #+#    #+#             */
/*   Updated: 2021/09/15 11:23:35 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int		fd[2];
	pid_t	pid;

	if (ac != 5)
	{
		ft_putendl_fd("Error\nusage: ./pipex infile cmd1 cmd1 outfile\n", 2);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == (-1))
	{
		ft_putendl_fd("Error\npipe failed\n", 2);
		exit(EXIT_FAILURE);
	}
	pipex_load(av, env, &pid, fd);
	exit (EXIT_SUCCESS);
}
