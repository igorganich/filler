/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inserting.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:14:17 by iganich           #+#    #+#             */
/*   Updated: 2018/07/03 17:16:25 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		clear_map(t_data *filler)
{
	int i;
	int l;

	i = -1;
	while (++i < filler->map_x)
	{
		l = -1;
		while (++l < filler->map_y)
		{
			if (filler->map[i][l] < -1000)
			{
				filler->map[i][l] += 1000;
				filler->map[i][l] -= 2 * filler->map[i][l];
			}
		}
	}
	return (0);
}

int		check_error(t_data *filler, int i, int l, int *z)
{
	if (filler->token[z[0]][z[1]] == '*')
	{
		if (filler->map[i][l] == -1)
			z[2]++;
		else if (filler->map[i][l] == 0)
			return (0);
		else
			z[3] = 1;
	}
	return (1);
}

int		insert_left_top(t_data *filler, int i, int l)
{
	int z[4];

	z[0] = -1;
	z[2] = 0;
	z[3] = 0;
	while (++z[0] < filler->token_x)
	{
		z[1] = -1;
		while (++z[1] < filler->token_y)
		{
			if (check_error(filler, i + z[0], l + z[1], z) == 0)
				return (clear_map(filler));
			if (filler->map[i + z[0]][l + z[1]] != -1 &&
				filler->map[i + z[0]][l + z[1]] != 0)
				filler->map[i + z[0]][l + z[1]] -=
				2 * filler->map[i + z[0]][l + z[1]] + 1000;
		}
	}
	clear_map(filler);
	if (z[3] == 1)
		return (z[2]);
	return (0);
}

int		tryins(t_data *filler, int i, int l)
{
	int ret;

	if (i + filler->token_x < filler->map_x)
		if (l + filler->token_y < filler->map_y)
			if (insert_left_top(filler, i, l) == 1)
				return (ft_printf("%d %d\n", i, l));
	if (i - filler->token_x >= 0 && l + filler->token_y < filler->map_y)
		if (insert_left_top(filler, i - filler->token_x + 1, l) == 1)
			return (ft_printf("%d %d\n", i - filler->token_x + 1, l));
	if (i + filler->token_x < filler->map_x && l - filler->token_y >= 0)
		if (insert_left_top(filler, i, l - filler->token_y + 1) == 1)
			return (ft_printf("%d %d\n", i, l - filler->token_y + 1));
	if (i - filler->token_x >= 0 && l - filler->token_y >= 0)
		if (insert_left_top(filler, i - filler->token_x + 1,
		l - filler->token_y + 1) == 1)
		{
			ret = ft_printf("%d %d\n", i - filler->token_x + 1,
			l - filler->token_y + 1);
			return (ret);
		}
	return (-1);
}

int		insert_token(t_data *filler, int current)
{
	int i;
	int l;
	int returner;

	i = -1;
	returner = -2;
	while (++i < filler->map_x)
	{
		l = -1;
		while (++l < filler->map_y)
			if (filler->map[i][l] == current)
			{
				returner = -1;
				if (tryins(filler, i, l) > 0)
				{
					return (1);
				}
			}
	}
	return (returner);
}
