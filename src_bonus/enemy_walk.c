/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_walk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 05:47:04 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/29 05:32:46 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_walk_2(t_window *pnc, int wall_check)
{
	if (pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x / PIXEL + 1] == '1'
		&& pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x / PIXEL
		- 1] == '1')
		return ;
	if (!wall_check && pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x
		/ PIXEL] != '1')
	{
		pnc->wall_current = pnc->wall_black;
		pnc->chr->enemy_current = pnc->chr->enemy_left;
		pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x / PIXEL] = '0';
		pnc->enemy_x -= PIXEL;
		pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x / PIXEL] = 'N';
	}
	if (wall_check && pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x
		/ PIXEL] != '1')
	{
		pnc->wall_current = pnc->wall_gold;
		pnc->chr->enemy_current = pnc->chr->enemy_right;
		pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x / PIXEL] = '0';
		pnc->enemy_x += PIXEL;
		pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x / PIXEL] = 'N';
	}
}

int	enemy_walk(t_window *pnc)
{
	static int	wall_check = 0;
	static int	i = 0;

	render_map(pnc);
	if (++i == 15)
		i = 0;
	else
		return (0);
	if (pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x
		/ PIXEL] == pnc->map->mappin[pnc->chr->y / PIXEL][pnc->chr->x / PIXEL]
		|| pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x / PIXEL
		+ 1] == 'C' || pnc->map->mappin[pnc->enemy_y / PIXEL][pnc->enemy_x
		/ PIXEL - 1] == 'C')
	{
		ft_putstr_fd("You lost to the enemy\n", 2);
		close_game_mlx(pnc);
	}
	if (pnc->map->mappin[pnc->enemy_y / PIXEL][(pnc->enemy_x / PIXEL)
		- 1] == '1')
		wall_check = 1;
	if (pnc->map->mappin[pnc->enemy_y / PIXEL][(pnc->enemy_x / PIXEL)
		+ 1] == '1')
		wall_check = 0;
	enemy_walk_2(pnc, wall_check);
	return (0);
}
