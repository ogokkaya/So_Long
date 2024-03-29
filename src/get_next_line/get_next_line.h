/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:47:43 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/22 16:46:52 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdlib.h>

char	*get_next_line(int fd);
void	*ft_free(char **str, int len);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *s, const char *s1);
char	*ft_substr(char const *s, unsigned int start, size_t len);
#endif