/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 13:42:40 by lanselin          #+#    #+#             */
/*   Updated: 2021/01/15 13:49:11 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int		get_next_line(int fd, char **line)
{
	int			reslen;
	char		*buffer;
	char		*result;
	static char	*tmp[4096];

	if (fd < 0 || fd > 4096 || !line || BUFFER_SIZE <= 0
			|| !(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	reslen = 0;
	result = (!tmp[fd] || !(tmp[fd][0])) ? ft_empty_string() : tmp[fd];
	if (!ft_iseol(result))
	{
		while (!ft_iseol(result)
				&& (reslen = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			result = ft_combine_result(result, buffer, reslen);
		}
	}
	if (ft_iseol(result) || reslen < BUFFER_SIZE)
	{
		free(buffer);
		return (return_result(result, line, &tmp[fd], reslen));
	}
	return (-1);
}

int		return_result(char *result, char **line, char **tmp, int reslen)
{
	int		size;

	if (reslen <= -1)
		return (-1);
	if (reslen == 0 && !ft_iseol(result))
	{
		*line = result;
		*tmp = NULL;
		return (0);
	}
	if (!ft_iseol(result))
	{
		*line = result;
		return (1);
	}
	size = ft_strlen(result, 0) - (ft_strlen(result, 1) + 1);
	*line = ft_substr(result, 0, ft_strlen(result, 1));
	*tmp = ft_substr(result, ft_strlen(result, 1) + 1, size);
	free(result);
	result = NULL;
	return (1);
}

char	*ft_combine_result(char *result, char *buffer, int reslen)
{

	buffer[reslen] = '\0';
	result = ft_strjoin(result, buffer);
	return (result);
}
