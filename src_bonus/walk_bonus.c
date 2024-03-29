/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 03:36:34 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/29 02:29:56 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "so_long_bonus.h"
#include <unistd.h>

static void	putchr(t_window *pnc, int keycode)
{
	if (keycode == 2)
		pnc->chr->chr_current = pnc->chr->chr_right;
	if (keycode == 0)
		pnc->chr->chr_current = pnc->chr->chr_left;
	if (keycode == 13)
		pnc->chr->chr_current = pnc->chr->chr_back;
	if (keycode == 1)
		pnc->chr->chr_current = pnc->chr->chr_front;
}

static void	move_player(t_window *pnc, int keycode, int x, int y)
{
	if (pnc->map->coin_cnt == 0 && pnc->map->mappin[pnc->map->exit_y
			/ PIXEL][pnc->map->exit_x / PIXEL] == pnc->map->mappin[y / PIXEL][x
				/ PIXEL])
	{
		pnc->chr->point += 1;
		(ft_putstr_fd("You win \n", 1), close_game_mlx(pnc));
	}
	if (pnc->map->mappin[y / PIXEL][x / PIXEL] != '1' && pnc->map->mappin[y
		/ PIXEL][x / PIXEL] == 'E' && pnc->map->exit_count != 0)
		ft_putstr_fd("Are you sure you collected all the coins?\n", 1);
	if (pnc->map->mappin[y / PIXEL][x / PIXEL] != '1' && pnc->map->mappin[y
		/ PIXEL][x / PIXEL] == 'N')
		(ft_putstr_fd("You lost to the enemy\n", 2), close_game_mlx(pnc));
	if (pnc->map->mappin[y / PIXEL][x / PIXEL] != '1' && pnc->map->mappin[y
		/ PIXEL][x / PIXEL] != 'E')
	{
		pnc->chr->point += 1;
		putchr(pnc, keycode);
		if (pnc->map->mappin[y / PIXEL][x / PIXEL] == 'C')
			pnc->map->coin_cnt -= 1;
		pnc->map->mappin[pnc->chr->y / PIXEL][pnc->chr->x / PIXEL] = '0';
		pnc->map->mappin[pnc->map->exit_y / PIXEL][pnc->map->exit_x
			/ PIXEL] = 'E';
		pnc->map->mappin[y / PIXEL][x / PIXEL] = 'P';
	}
}

int	walk(int keycode, void *param)
{
	t_window	*pnc;

	pnc = param;
	mlx_clear_window(pnc->mlx, pnc->win);
	if (keycode == 53)
		close_game_mlx(pnc);
	if (keycode == 2)
		move_player(pnc, keycode, pnc->chr->x + PIXEL, pnc->chr->y);
	if (keycode == 0)
		move_player(pnc, keycode, pnc->chr->x - PIXEL, pnc->chr->y);
	if (keycode == 13)
		move_player(pnc, keycode, pnc->chr->x, pnc->chr->y - PIXEL);
	if (keycode == 1)
		move_player(pnc, keycode, pnc->chr->x, pnc->chr->y + PIXEL);
	render_map(pnc);
	return (keycode);
}
