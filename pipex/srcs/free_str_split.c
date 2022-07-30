/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: florianmastorakis <marvin@42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 16:32:27 by florianma         #+#    #+#             */
/*   Updated: 2021/09/11 17:29:41 by florianma        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_str(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
