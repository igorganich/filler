/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 01:29:12 by iganich           #+#    #+#             */
/*   Updated: 2018/07/03 17:13:20 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		enter_numbers(t_data *filler, int current)
{
	int i;
	int l;
	int flag;
	int flag2;

	i = -1;
	flag = 0;
	flag2 = 0;
	while (++i < filler->map_x)
	{
		l = -1;
		while (++l < filler->map_y)
		{
			if (filler->map[i][l] == current)
				flag = insert_numbers(filler, i, l, current);
			if (!flag2 && flag)
				flag2 = flag;
		}
	}
	return (flag2);
}

int		check_and_change(t_data *filler, int i, int l, int current)
{
	int flag;

	flag = (filler->map[i][l] == -2);
	if (filler->map[i][l] == -2)
		filler->map[i][l] = current + 1;
	return (flag);
}

int		insert_numbers(t_data *filler, int i, int l, int current)
{
	int flag;

	flag = 0;
	if (i + 1 < filler->map_x)
		flag += check_and_change(filler, i + 1, l, current);
	if (i - 1 >= 0)
		flag += check_and_change(filler, i - 1, l, current);
	if (l + 1 < filler->map_y)
		flag += check_and_change(filler, i, l + 1, current);
	if (l - 1 >= 0)
		flag += check_and_change(filler, i, l - 1, current);
	return (flag > 0);
}

void	goparse(t_data *filler)
{
	int current;
	int ret;

	current = -1;
	ret = 0;
	while (enter_numbers(filler, ++current))
		;
	current = find_best(filler);
	current = current > 0 ? current : 1;
	while ((ret = insert_token(filler, current)) == -1)
		current++;
	if (ret == -2)
		if (insert_token(filler, -2) != 1)
		{
			ft_printf("0 0\n");
			filler->end = 1;
		}
}

int		main(void)
{
	t_data	*filler;
	char	*ln;

	filler = ft_memalloc(sizeof(t_data));
	if (!filler)
		return (-1);
	read_to_end(&ln);
	filler->player = (ln[10] == '1') ? 'o' : 'x';
	while (1)
	{
		read_to_end(&ln);
		check_map_size(ln, filler);
		create_map(filler);
		goparse(filler);
		if (filler->end == 1)
			break ;
	}
	freemap(filler->map, filler->map_x);
	free(filler->map);
	freetoken(filler->token, filler->token_x - 1, NULL, NULL);
	free(filler);
	return (0);
}
