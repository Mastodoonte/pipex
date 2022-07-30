/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:30:37 by florianma         #+#    #+#             */
/*   Updated: 2021/09/11 17:28:05 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(int *fd, char **av, char **env)
{
	int		infile;
	char	*path;
	char	**cmd1;

	infile = open(av[1], O_RDONLY);
	if (infile < 0)
		inexistant_error_file();
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (*env == NULL)
		exit(EXIT_FAILURE);
	cmd1 = ft_split(av[2], ' ');
	if (*cmd1 == NULL)
	{
		if (cmd1)
			free_split(cmd1);
		exit(EXIT_FAILURE);
	}
	path = get_path(env, cmd1);
	if (execve(path, cmd1, env) == -1)
		none_valid_command(cmd1, path);
}

void	parent_process(int *fd, char **av, char **env, pid_t **pid)
{
	int		outfile;
	char	*path;
	char	**cmd2;

	outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		inexistant_error_file();
	waitpid(**pid, 0, WNOHANG);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	if (*env == NULL)
		exit(EXIT_FAILURE);
	cmd2 = ft_split(av[3], ' ');
	if (*cmd2 == NULL)
	{
		if (cmd2)
			free_split(cmd2);
		exit(EXIT_FAILURE);
	}
	path = get_path(env, cmd2);
	if (execve(path, cmd2, env) == -1)
		none_valid_command(cmd2, path);
}

void	pipex_load(char **av, char **env, pid_t *pid, int *fd)
{
	*pid = fork();
	if (*pid == (-1))
	{
		ft_putendl_fd("Error\nfork failed\n", 2);
		exit(EXIT_FAILURE);
	}
	else if (*pid == 0)
	{
		child_process(fd, av, env);
	}
	else if (*pid > 0)
	{
		parent_process(fd, av, env, &pid);
	}
}
