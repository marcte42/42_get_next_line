/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:33:17 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/11/23 22:20:42 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t			i;

	i = -1;
	while (s[++i])
		if (s[i] == c)
			return ((char *)&s[i]);
	return ((c == '\0') ? (char *)&s[i] : NULL);
}

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t i;

	i = -1;
	while (src[++i] && i < n)
		dst[i] = src[i];
	dst[i] = '\0';
	return (dst);
}

char	*ft_strdup(const char *s1)
{
	char	*dst;
	size_t	len;

	if (!s1)
	{
		if (!(dst = (char *)malloc(sizeof(char))))
			return (0);
		dst[0] = '\0';
	}
	else
	{
		len = ft_strlen(s1);
		if (!(dst = (char *)malloc((len + 1) * sizeof(char))))
			return (0);
		ft_strncpy(dst, s1, len);
	}
	return (dst);
}

char	*ft_strcat(char *s1, const char *s2)
{
	ft_strncpy(s1 + ft_strlen(s1), s2, ft_strlen(s2));
	return (s1);
}
