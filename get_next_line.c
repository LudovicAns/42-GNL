/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:12:52 by lanselin          #+#    #+#             */
/*   Updated: 2021/02/05 14:12:55 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			len;
	char		*buffer;
	char		*res;
	static char	*tmp;

	if (fd < 0 || fd > 4096 || !line || BUFFER_SIZE <= 0)
		return (-1);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (-1);
	res = (!tmp || !(tmp[0])) ? ft_strdup("\0") : ft_strdup(tmp);
	len = 0;
	if (!iseol(res))
		len = process_read(fd, &buffer, &res);
	free(buffer);
	if (iseol(res) || len < BUFFER_SIZE)
	{
		len = return_result(res, line, &tmp, len);
		secure_free(&res);
		return (len);
	}
	return (-1);
}

void	secure_free(char **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

int		process_read(int fd, char **buffer, char **res)
{
	int len;

	len = 0;
	len = (!iseol(*res)) ? read(fd, *buffer, BUFFER_SIZE) : 0;
	*res =  len > 0 ? combine(*res, *buffer, len) : *res;
	while (!iseol(*res) && len > 0)
	{
		len = !iseol(*res) && len > 0 ? read(fd, *buffer, BUFFER_SIZE) : 0;
		*res =  len > 0 ? combine(*res, *buffer, len) : *res;
	}
	return (len);
}

int		return_result(char *res, char **line, char **tmp, int len)
{
	int		size;

	if (len <= -1)
		return (-1);
	if (len == 0 && !iseol(res))
	{
		*line = ft_strdup(res);
		secure_free(&*tmp);
		return (0);
	}
	if (!iseol(res))
	{
		*line = ft_strdup(res);
		return (1);
	}
	size = ft_strlen(res, 0) - (ft_strlen(res, 1) + 1);
	*line = ft_substr(res, 0, ft_strlen(res, 1));
	secure_free(&*tmp);
	*tmp = ft_substr(res, ft_strlen(res, 1) + 1, size);
	return (1);
}

char	*combine(char *res, char *buffer, int len)
{
	void *ptr_saver;

	buffer[len] = '\0';
	ptr_saver = res;
	res = ft_strjoin(res, buffer);
	free(ptr_saver);
	return (res);
}
