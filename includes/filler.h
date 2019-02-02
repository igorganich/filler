/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iganich <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 04:46:51 by iganich           #+#    #+#             */
/*   Updated: 2018/07/03 17:06:57 by iganich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include <fcntl.h>
# include "../ft_printf/headers/ft_printf.h"
# include "../libft/includes/libft.h"

typedef struct	s_data
{
	char	player;
	int		map_x;
	int		map_y;
	int		**map;
	int		token_x;
	int		token_y;
	char	**token;
	int		end;
}				t_data;

int				insert_numbers(t_data *filler, int i, int l, int current);
int				find_best(t_data *filler);
int				insert_token(t_data *filler, int current);
int				read_to_end(char **line);
void			create_map(t_data *filler);
void			freemap(int **map, int size);
void			freetoken(char **token, int size, char *str, t_data *filler);
void			check_map_size(char *line, t_data *filler);
void			read_one_token(char **line, int size);
int				*line_to_int(char *line, t_data *filler);

#endif
