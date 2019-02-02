/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   different.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:17:07 by iganich           #+#    #+#             */
/*   Updated: 2018/07/03 17:13:51 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	freemap(int **map, int size)
{
	int i;

	i = -1;
	while (++i < size)
		if (map && map[i])
			free(map[i]);
}

void	freetoken(char **token, int size, char *line, t_data *filler)
{
	int i;

	i = -1;
	while (++i <= size)
		if (token && token[i])
			free(token[i]);
	free(token);
	if (line != NULL)
	{
		line = ft_strchr(line, ' ') + 1;
		filler->token_x = ft_atoi(line);
		line = ft_strchr(line, ' ') + 1;
		filler->token_y = ft_atoi(line);
	}
}

void	check_map_size(char *line, t_data *filler)
{
	line = ft_strchr(line, ' ') + 1;
	filler->map_x = ft_atoi(line);
	filler->map_x = ft_atoi(line);
	line = ft_strchr(line, ' ') + 1;
	filler->map_y = ft_atoi(line);
	if (!filler->map)
	{
		filler->map = (int**)ft_memalloc(sizeof(int*) * (filler->map_x + 1));
		filler->token = ft_memalloc(1);
	}
}

int		*line_to_int(char *line, t_data *filler)
{
	int *newint;
	int i;
	int len;

	len = ft_strlen(line);
	newint = (int*)ft_memalloc(sizeof(int) * (len + 1));
	i = -1;
	while (++i < len)
	{
		if (line[i] == 'O' || line[i] == 'X')
			line[i] = line[i] + ('a' - 'A');
		if (line[i] == filler->player)
			newint[i] = -1;
		else if (line[i] == '.')
			newint[i] = -2;
		else
			newint[i] = 0;
	}
	return (newint);
}

void	create_map(t_data *filler)
{
	char	*line;
	int		count;

	count = -1;
	freemap(filler->map, filler->map_x);
	while (++count <= filler->map_x && read_to_end(&line) > 0)
	{
		if (count != 0)
			filler->map[count - 1] = line_to_int(line + 4, filler);
		free(line);
	}
	read_to_end(&line);
	freetoken(filler->token, filler->token_x - 1, line, filler);
	count = 1;
	filler->token = ft_memalloc(sizeof(char*) * filler->token_x);
	while (1)
	{
		read_one_token(&line, filler->token_y);
		filler->token[count - 1] = ft_strdup(line);
		free(line);
		count++;
		if (count > filler->token_x)
			break ;
	}
}
