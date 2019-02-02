/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkingmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/03 15:21:15 by iganich           #+#    #+#             */
/*   Updated: 2018/07/03 16:59:40 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	compare_it(int *best, int forcomp)
{
	if (*best == -1)
		*best = forcomp;
	if (*best > forcomp && forcomp != -1)
		*best = forcomp;
}

void	check_is_best(t_data *filler, int *best, int i, int l)
{
	if (i + 1 < filler->map_x)
		compare_it(best, filler->map[i + 1][l]);
	if (i - 1 >= 0)
		compare_it(best, filler->map[i - 1][l]);
	if (l + 1 < filler->map_y)
		compare_it(best, filler->map[i][l + 1]);
	if (l - 1 >= 0)
		compare_it(best, filler->map[i][l - 1]);
}

int		find_best(t_data *filler)
{
	int best;
	int i;
	int l;

	best = -1;
	i = -1;
	while (++i < filler->map_x)
	{
		l = -1;
		while (++l < filler->map_y)
			if (filler->map[i][l] == -1)
				check_is_best(filler, &best, i, l);
	}
	return (best + 2 - filler->token_x - filler->token_y);
}
