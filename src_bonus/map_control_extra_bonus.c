/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_extra_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 06:06:01 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/29 05:43:19 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "so_long_bonus.h"
#include <stdlib.h>

void	coin_control(t_window *pnc)
{
	int	i;
	int	j;

	i = -1;
	while (pnc->map->mappin[++i])
	{
		j = -1;
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'C')
				pnc->map->coin_cnt += 1;
		}
	}
	if (pnc->map->coin_cnt <= 0)
	{
		(ft_putstr_fd("Not found coin in map\n", 2), close_game_usual(pnc),
			exit(1));
	}
}

void	enemy_control(t_window *pnc)
{
	int	i;
	int	j;

	i = -1;
	pnc->enemy_x = 0;
	pnc->enemy_y = 0;
	pnc->map->enemy_cnt = 0;
	while (pnc->map->mappin[++i])
	{
		j = -1;
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'N')
			{
				pnc->map->enemy_cnt += 1;
				pnc->enemy_x = j;
				pnc->enemy_y = i;
			}
		}
	}
	if (pnc->map->enemy_cnt <= 0)
	{
		ft_putstr_fd("Not Found enemy in map\n", 2);
		(close_game_usual(pnc), exit(1));
	}
}

void	close_game_usual(t_window *pnc)
{
	int	i;

	i = -1;
	if (pnc->map->mappin)
	{
		while (pnc->map->mappin[++i])
			free(pnc->map->mappin[i]);
		free(pnc->map->mappin);
	}
	i = -1;
	if (pnc->map->clone_map)
	{
		while (pnc->map->clone_map[++i])
			free(pnc->map->clone_map[i]);
		free(pnc->map->clone_map);
	}
	if (pnc->map)
		free(pnc->map);
	if (pnc->chr)
		free(pnc->chr);
}

int	close_game_mlx(t_window *pnc)
{
	if (pnc->chr->chr_front)
		mlx_destroy_image(pnc->mlx, pnc->chr->chr_front);
	if (pnc->chr->chr_back)
		mlx_destroy_image(pnc->mlx, pnc->chr->chr_back);
	if (pnc->chr->chr_right)
		mlx_destroy_image(pnc->mlx, pnc->chr->chr_right);
	if (pnc->chr->chr_left)
		mlx_destroy_image(pnc->mlx, pnc->chr->chr_left);
	if (pnc->img_bg)
		mlx_destroy_image(pnc->mlx, pnc->img_bg);
	if (pnc->chr->enemy_left)
		mlx_destroy_image(pnc->mlx, pnc->chr->enemy_left);
	if (pnc->chr->enemy_right)
		mlx_destroy_image(pnc->mlx, pnc->chr->enemy_right);
	if (pnc->wall_gold)
		mlx_destroy_image(pnc->mlx, pnc->wall_gold);
	if (pnc->wall_black)
		mlx_destroy_image(pnc->mlx, pnc->wall_black);
	if (pnc->coin_bg)
		mlx_destroy_image(pnc->mlx, pnc->coin_bg);
	if (pnc->exit_bg)
		mlx_destroy_image(pnc->mlx, pnc->exit_bg);
	mlx_destroy_window(pnc->mlx, pnc->win);
	close_game_usual(pnc);
	return (exit(0), 0);
}
