/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 03:55:41 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/29 06:24:12 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.h"
#include "so_long.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

static void	read_checknl(int fd, char *str, char *ptr, char c)
{
	if (c == '\n')
	{
		ft_putstr_fd("Error\nEmpty map", 2);
		if (str)
			free(str);
		if (ptr)
			free(ptr);
		close(fd);
		exit(1);
	}
}

static void	ptrappend(char **ptr, char *str)
{
	char	*tmp;

	if (!*ptr && str)
	{
		*ptr = ft_strdup(str);
		if (!*ptr)
			free(str);
		return ;
	}
	tmp = *ptr;
	*ptr = ft_strjoin(*ptr, str);
	if (tmp)
		free(tmp);
	if (!*ptr)
	{
		free(str);
		ft_putstr_fd("Error\nString addition could not be done", 2);
		exit(1);
	}
}

static char	*file_to_read(char *path)
{
	char	*str;
	char	*ptr;
	int		fd;

	ptr = NULL;
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		perror("Map file path");
		exit(1);
	}
	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		read_checknl(fd, str, ptr, str[0]);
		ptrappend(&ptr, str);
		free(str);
	}
	return (close(fd), ptr);
}

void	read_map(t_window *pnc, char *path)
{
	pnc->str = file_to_read(path);
	if (!pnc->str)
		(ft_putstr_fd("Error\nCould not create map", 2), exit(1));
	pnc->map = ft_calloc(1, sizeof(t_map));
	if (!pnc->map)
		return (ft_putstr_fd("Error: Calloc read map", 2),
			close_game_usual(pnc), exit(1));
	pnc->map->mappin = ft_split(pnc->str, '\n');
	pnc->map->clone_map = ft_split(pnc->str, '\n');
	free(pnc->str);
	if (!pnc->map->mappin || !pnc->map->clone_map)
		(ft_putstr_fd("Error\nSplit could not be created", 2),
			close_game_usual(pnc));
	while (pnc->map->mappin[pnc->map->h])
		pnc->map->h++;
	pnc->map->w = ft_strlen(pnc->map->mappin[0]);
	pnc->height = pnc->map->h * PIXEL;
	pnc->width = pnc->map->w * PIXEL;
}
