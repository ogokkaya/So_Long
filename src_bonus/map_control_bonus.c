/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_control_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 04:27:46 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/27 05:29:42 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"
#include "get_next_line/get_next_line.h"

void	map_size_control(t_window *pnc)
{
	int		i;
	size_t	len;

	i = 0;
	len = pnc->map->w;
	while (pnc->map->mappin[i])
	{
		if (ft_strlen(pnc->map->mappin[i]) != len)
		{
			ft_putstr_fd("Error\nMap size", 2);
			close_game_usual(pnc);
			exit(1);
		}
		i++;
	}
}

void	char_control(t_window *pnc)
{
	int	i;
	int	j;

	i = -1;
	while (pnc->map->mappin[++i])
	{
		j = -1;
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] != '0' && pnc->map->mappin[i][j] != '1'
				&& pnc->map->mappin[i][j] != 'P'
				&& pnc->map->mappin[i][j] != 'C'
				&& pnc->map->mappin[i][j] != 'E'
				&& pnc->map->mappin[i][j] != 'N')
			{
				ft_putstr_fd("Error\nUndefined Char", 2);
				close_game_usual(pnc);
				exit(1);
			}
		}
	}
}

void	player_control(t_window *pnc)
{
	int	i;
	int	j;

	i = 0;
	while (pnc->map->mappin[i])
	{
		j = 0;
		while (pnc->map->mappin[i][j])
		{
			if (pnc->map->mappin[i][j] == 'P')
			{
				pnc->map->p_cnt += 1;
				pnc->chr->x = j;
				pnc->chr->y = i;
			}
			j++;
		}
		i++;
	}
	if (pnc->map->p_cnt == 0 || pnc->map->p_cnt > 1)
		(ft_putstr_fd("Error\nNo pleyer has been spawned", 2),
			close_game_usual(pnc), exit(1));
}

void	wall_control(t_window *pnc)
{
	int	i;
	int	last;

	i = -1;
	while (pnc->map->mappin[0][++i])
	{
		if (pnc->map->mappin[0][i] != '1' || pnc->map->mappin[pnc->map->h
			- 1][i] != '1')
		{
			(ft_putstr_fd("Error\nWall", 2), close_game_usual(pnc), exit(1));
		}
	}
	i = -1;
	last = pnc->map->w - 1;
	while (pnc->map->mappin[++i])
	{
		if (pnc->map->mappin[i][0] != '1' || pnc->map->mappin[i][last] != '1')
		{
			(ft_putstr_fd("Error\nWall", 2), close_game_usual(pnc), exit(1));
		}
	}
}

void	exit_control(t_window *pnc)
{
	int	i;
	int	j;

	i = -1;
	while (pnc->map->mappin[++i])
	{
		j = -1;
		while (pnc->map->mappin[i][++j])
		{
			if (pnc->map->mappin[i][j] == 'E')
			{
				pnc->map->exit_count += 1;
			}
		}
	}
	if (pnc->map->exit_count < 1)
	{
		(ft_putstr_fd("Error\nNo exit", 2), close_game_usual(pnc), exit(1));
	}
	if (pnc->map->exit_count > 1)
	{
		(ft_putstr_fd("Error\nMore than one exit", 2), close_game_usual(pnc),
			exit(1));
	}
}
