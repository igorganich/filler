/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:12:03 by iganich           #+#    #+#             */
/*   Updated: 2018/07/03 15:36:55 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	read_one_token(char **line, int size)
{
	char	buffer[100];
	int		i;

	i = -1;
	while (++i <= size)
		read(0, buffer + i, 1);
	buffer[i] = '\0';
	*line = ft_strdup(buffer);
}

int		read_to_end(char **line)
{
	char	buffer[100];
	int		i;

	i = -1;
	while (++i != -1)
	{
		if (read(0, buffer + i, 1) == 0)
			break ;
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			break ;
		}
	}
	*line = ft_strdup(buffer);
	return (1);
}
