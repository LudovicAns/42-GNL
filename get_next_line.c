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

void	*update_ptr(void *old_ptr, void *new_ptr)
{;
	free(old_ptr);
	//old_ptr = NULL;
	return (new_ptr);
}

int		gnl_result(int readed_size, char **line, char *storage, char *buffer)
{
	if (readed_size < 0)
		return (-1);
	printf("readed_size = %d\n", readed_size);
	printf("Storage = %s\n", storage);
	if (has_eol(storage) && readed_size > 0)
	{
		*line = extract_str(0, ft_strlen(storage, 1) - 1, storage);
		storage = (char *)update_ptr(storage, extract_str(ft_strlen(storage, 1) + 1, ft_strlen(storage, 0) - 1, storage));
		return (1);
	}
	else
	{
		*line = storage;
		free(buffer);
		return (0);
	}
}

int		get_next_line(int fd, char **line)
{
	static char *storage;
	char		*buffer;
	int			readed_size;

	if (fd < 0 || fd > 500 || !line || BUFFER_SIZE <= 0
		|| !(buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);

	if (!storage || !storage[0])
		storage = empty_str();

	if (!has_eol(storage))
	{
		while (!has_eol(storage) && (readed_size = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			buffer[readed_size] = '\0';
			storage = (char *)update_ptr(storage, ft_strjoin(storage, buffer));
		}
		buffer[readed_size] = '\0';
		storage = (char *)update_ptr(storage, ft_strjoin(storage, buffer));
	}

	return (gnl_result(readed_size, line, storage, buffer));
}

int main(void)
{
	char	*line;
	int		value = 1;
	int		fd = open("nl", O_RDONLY);


	get_next_line(fd, &line);
	get_next_line(fd, &line);
	//while (value)
	//{
	//	value = get_next_line(fd, &line);
	//	printf("%d. %s\n", value, line);
	//}

	return (0);
}
