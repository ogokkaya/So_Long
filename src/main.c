/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:40:56 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/29 02:16:52 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <stdio.h>
#include <stdlib.h>

static void	file_name_check(char *str)
{
	size_t	i;

	if (!str)
		return (perror("File name check"), exit(1));
	i = ft_strlen(str);
	if (str[i - 1] != 'r' && str[i - 2] != 'e' && str[i - 3] != 'b' && str[i
			- 4] != 'e')
		return (perror("File name check"), exit(1));
}

static void	game_init_control(t_window *pnc, char *path)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	read_map(pnc, path);
	pnc->chr = malloc(sizeof(t_char));
	if (!pnc->chr)
	{
		perror("pnc->chr");
		exit(1);
	}
	map_size_control(pnc);
	char_control(pnc);
	player_control(pnc);
	wall_control(pnc);
	exit_control(pnc);
	coin_control(pnc);
	path_finder_control(pnc);
	render_img(pnc, x, y);
}

int	main(int ac, char **av)
{
	t_window	so_long;

	if (ac == 2)
	{
		file_name_check(av[1]);
		game_init_control(&so_long, av[1]);
		render_map(&so_long);
		mlx_hook(so_long.win, 2, 0, walk, &so_long);
		mlx_hook(so_long.win, 17, 0, close_game_mlx, &so_long);
		mlx_loop(so_long.mlx);
	}
	else
	{
		ft_putstr_fd("Error\nNone Argument\n", 2);
		return (1);
	}
	return (0);
}
