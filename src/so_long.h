/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 23:43:15 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/27 05:32:05 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#define SO_LONG_H
#define PIXEL 64

#include <sys/_types/_size_t.h>

typedef struct s_map
{
	char	**mappin;
	char	**clone_map;
	int		w;
	int		h;
	int		exit_x;
	int		exit_y;
	int		p_cnt;
	int		exit_count;
	int		coin_cnt;
}			t_map;

typedef struct s_char
{
	int		x;
	int		y;
	int		point;
	void	*chr_front;
	void	*chr_back;
	void	*chr_left;
	void	*chr_right;
	void	*chr_current;
}			t_char;

typedef struct s_window
{
	t_map	*map;
	t_char	*chr;
	char	*str;
	int		coin;
	int		exit;
	void	*win;
	void	*mlx;
	void	*img_bg;
	void	*wall_bg;
	void	*coin_bg;
	void	*exit_bg;
	int		height;
	int		width;
}			t_window;

void		ft_putstr_fd(char *s, int fd);
void		*ft_calloc(size_t count, size_t size);
void		read_map(t_window *pnc, char *path);
void		map_size_control(t_window *pnc);
void		player_control(t_window *pnc);
void		wall_control(t_window *pnc);
void		exit_control(t_window *pnc);
void		coin_control(t_window *pnc);
void		char_control(t_window *pnc);
void		path_finder_control(t_window *pnc);
void		render_img(t_window *pnc, int x, int y);
void		close_game_usual(t_window *pnc);
int			close_game_mlx(t_window *pnc);
void		render_map(t_window *pnc);
char		*ft_itoa(int n);
char		**ft_split(char const *s, char c);
int			walk(int keycode, void *param);
char		**ft_split(char const *s, char c);
char		*ft_itoa(int n);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);