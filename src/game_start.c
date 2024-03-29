/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:17:40 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/29 05:50:24 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "so_long.h"

void	render_img(t_window *pnc, int x, int y)
{
	pnc->mlx = mlx_init();
	pnc->win = mlx_new_window(pnc->mlx, pnc->width, pnc->height, "SONIC");
	if (!pnc->mlx || !pnc->win)
		(ft_putstr_fd("Error\nFailed to create mlx", 2), close_game_mlx(pnc));
	pnc->chr->chr_front = mlx_xpm_file_to_image(pnc->mlx,
			"./xpm/sonic_front.xpm", &x, &y);
	pnc->chr->chr_back = mlx_xpm_file_to_image(pnc->mlx, "./xpm/sonic_back.xpm",
			&x, &y);
	pnc->chr->chr_right = mlx_xpm_file_to_image(pnc->mlx,
			"./xpm/sonic_right.xpm", &x, &y);
	pnc->chr->chr_left = mlx_xpm_file_to_image(pnc->mlx, "./xpm/sonic_left.xpm",
			&x, &y);
	pnc->chr->chr_current = pnc->chr->chr_front;
	pnc->img_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/background.xpm", &x,
			&y);
	pnc->wall_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/wall_black.xpm", &x,
			&y);
	pnc->coin_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/coin.xpm", &x, &y);
	pnc->exit_bg = mlx_xpm_file_to_image(pnc->mlx, "./xpm/exit.xpm", &x, &y);
	if (!pnc->chr->chr_front || !pnc->chr->chr_back || !pnc->chr->chr_right
		|| !pnc->chr->chr_left || !pnc->img_bg || !pnc->wall_bg || !pnc->coin_bg
		|| !pnc->exit_bg)
		(ft_putstr_fd("Error\nXpm file cannot be opened", 2),
			close_game_mlx(pnc));
}

static void	put_img(char c, t_window *pnc, int x, int y)
{
	mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->img_bg, x, y);
	if (c == 'P')
	{
		pnc->chr->x = x;
		pnc->chr->y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->chr->chr_current, x,
			y);
	}
	if (c == '1')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->wall_bg, x, y);
	if (c == 'C')
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->coin_bg, x, y);
	if (c == 'E')
	{
		pnc->map->exit_x = x;
		pnc->map->exit_y = y;
		mlx_put_image_to_window(pnc->mlx, pnc->win, pnc->exit_bg, x, y);
	}
}

void	render_map(t_window *pnc)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	y = 0;
	while (pnc->map->mappin[i])
	{
		x = 0;
		j = 0;
		while (pnc->map->mappin[i][j])
		{
			put_img(pnc->map->mappin[i][j], pnc, x, y);
			j++;
			x += PIXEL;
		}
		i++;
		y += PIXEL;
	}
}
