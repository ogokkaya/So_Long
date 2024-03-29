/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finder_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:28:40 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/27 06:42:44 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include <stdlib.h>

static int	path_finder(t_window *pnc, int x, int y)
{
	if (pnc->map->clone_map[y][x] == '1')
		return (0);
	else if (pnc->map->clone_map[y][x] == 'N')
		pnc->chr->enemy_pthfind += 1;
	else if (pnc->map->clone_map[y][x] == 'C')
		pnc->coin += 1;
	else if (pnc->map->clone_map[y][x] == 'E')
		pnc->exit += 1;
	else if (pnc->map->clone_map[y][x] != 'P'
		&& pnc->map->clone_map[y][x] != '0' && pnc->map->clone_map[y][x] != 'N')
		(ft_putstr_fd("Error\nUndefined char", 2), close_game_usual(pnc),
			exit(1));
	pnc->map->clone_map[y][x] = '1';
	path_finder(pnc, x - 1, y);
	path_finder(pnc, x, y - 1);
	path_finder(pnc, x + 1, y);
	path_finder(pnc, x, y + 1);
	return (0);
}

void	path_finder_control(t_window *pnc)
{
	pnc->exit = 0;
	pnc->coin = 0;
	path_finder(pnc, pnc->chr->x, pnc->chr->y);
	if (pnc->coin != pnc->map->coin_cnt)
		(ft_putstr_fd("Error\nUnreachable coin", 2), close_game_usual(pnc),
			exit(1));
	if (pnc->exit != 1)
		(ft_putstr_fd("Error\nUnreachable exit", 2), close_game_usual(pnc),
			exit(1));
	if (pnc->chr->enemy_pthfind != pnc->map->enemy_cnt)
		(ft_putstr_fd("Error\nUnreachable enemy", 2), close_game_usual(pnc),
			exit(1));
}
