/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haslan <haslan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:23:37 by haslan            #+#    #+#             */
/*   Updated: 2023/11/28 18:16:06 by haslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <unistd.h>

static	char	*ft_strjoin(char *first_part, char *last_part)
{
	char	*result;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (!first_part)
	{
		first_part = (char *)malloc(1);
		if (!first_part)
			return (NULL);
		first_part[0] = '\0';
	}
	result = (char *)malloc(ft_strlen(first_part) + ft_strlen(last_part) + 1);
	if (!result)
		return (ft_free(first_part));
	while (first_part[++i] != '\0')
		result[i] = first_part[i];
	while (last_part[++j] != '\0')
		result[i++] = last_part[j];
	result[i] = '\0';
	ft_free(first_part);
	return (result);
}

static	char	*read_line(int fd, char *ft_past)
{
	char	*read_buf;
	int		nobr;

	read_buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!read_buf)
		return (ft_free(ft_past));
	read_buf[0] = '\0';
	while (!ft_have_newline(read_buf))
	{
		nobr = read(fd, read_buf, BUFFER_SIZE);
		if (nobr == -1 || nobr == 0)
			break ;
		read_buf[nobr] = '\0';
		ft_past = ft_strjoin(ft_past, read_buf);
		if (!ft_past)
			break ;
	}
	ft_free(read_buf);
	if (nobr == -1)
		return (ft_free(ft_past));
	return (ft_past);
}

char	*get_next_line(int fd)
{
	char		*re_line;
	static char	*ft_past[5000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!ft_have_newline (ft_past[fd]))
		ft_past[fd] = read_line (fd, ft_past[fd]);
	if (!ft_past[fd])
		return (NULL);
	re_line = ft_before_nevline (ft_past[fd]);
	if (!re_line)
	{
		ft_free(ft_past[fd]);
		ft_past[fd] = NULL;
		return (NULL);
	}
	ft_past[fd] = ft_after_newline(ft_past[fd]);
	return (re_line);
}
