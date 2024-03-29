/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ogokkaya <ogokkaya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 21:47:48 by ogokkaya          #+#    #+#             */
/*   Updated: 2024/03/22 16:46:45 by ogokkaya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*dst;
	int		i;

	if (!str)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	if (!dst)
		return (NULL);
	i = -1;
	while (str[++i])
		dst[i] = str[i];
	dst[i] = '\0';
	return (dst);
}

void	*ft_free(char **buffer, int option)
{
	char	*str;

	if (!*buffer)
		return (NULL);
	if (option == 0)
	{
		if (*buffer)
		{
			free(*buffer);
			*buffer = NULL;
		}
		return (NULL);
	}
	else if (option == 1)
	{
		str = ft_strdup(*buffer);
		free(*buffer);
		*buffer = NULL;
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin(const char *s, const char *s1)
{
	char	*s2;
	int		i;
	int		j;

	if (!s || !s1)
		return (NULL);
	s2 = (char *)malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(s1) + 1));
	if (!s2)
		return (NULL);
	i = -1;
	while (s[++i])
		s2[i] = s[i];
	j = -1;
	while (s1[++j])
		s2[i + j] = s1[j];
	s2[i + j] = '\0';
	return (s2);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	end;

	if (!s || len <= 0)
		return (NULL);
	end = ft_strlen(s);
	if (len > end)
		len = end;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	i = start;
	j = 0;
	while (i < end && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
