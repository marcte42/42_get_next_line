/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mterkhoy <mterkhoy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 15:04:10 by mterkhoy          #+#    #+#             */
/*   Updated: 2020/11/23 22:20:47 by mterkhoy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len;
	char	*str;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	str[0] = '\0';
	ft_strcat(str, s1);
	ft_strcat(str, s2);
	free(s1);
	return (str);
}

int		ft_process_rest(char **rest, char **line)
{
	char *tmp;
	char *n_char;

	if (!(*rest))
		return (1);
	n_char = ft_strchr(*rest, '\n');
	if (n_char)
	{
		tmp = *rest;
		if (!(*line = malloc((n_char - *rest + 1) * sizeof(char))))
			return (-1);
		ft_strncpy(*line, *rest, n_char - *rest);
		if (!(*rest = ft_strdup(n_char + 1)))
			return (-1);
		free(tmp);
	}
	return (1);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFFER_SIZE + 1];
	static char		*rest;
	int				rt;

	if (!line || fd < 0 || BUFFER_SIZE <= 0)
		return (-1);
	if (rest && ft_strchr(rest, '\n'))
		return (ft_process_rest(&rest, line));
	if ((rt = read(fd, buf, BUFFER_SIZE)) < 0)
		return (-1);
	buf[rt] = '\0';
	if (rt == 0)
	{
		if (!(*line = ft_strdup(rest)))
			return (-1);
		if (rest)
		{
			free(rest);
			rest = NULL;
		}
		return (0);
	}
	if (!(rest = ft_strjoin(rest, buf)))
		return (-1);
	return (get_next_line(fd, line));
}
