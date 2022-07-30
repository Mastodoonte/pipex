/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 18:01:47 by florianma         #+#    #+#             */
/*   Updated: 2021/09/11 17:23:34 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <sys/wait.h>

			/*Processus*/
void	pipex_load(char **av, char **env, pid_t *pid, int *fd);
void	parent_process(int *fd, char **av, char **env, pid_t **pid);
void	child_process(int *fd, char **av, char **env);
			/*Parsing*/
void	*parsing_path(char **env, char *cmd);
void	*get_path(char **env, char **cmd);
			/*Error gestion*/
void	inexistant_error_file(void);
void	none_valid_command(char **cmd, char *path);
			/*fonction de free*/
void	free_split(char **str);
void	free_str(char **str);
			/*utils*/
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t length);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);

#endif
