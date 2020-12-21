/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin </var/mail/lanselin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:11:34 by lanselin          #+#    #+#             */
/*   Updated: 2020/12/21 20:11:39 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
    int         reslen;
    char        *buffer;
    char        *result;
    static char *tmp;

    if (fd < 0 || !line || BUFFER_SIZE <= 0 
            || !(buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE + 1)))
        return (-1);
    reslen = 0;
    result = (!tmp) ? ft_empty_string() : tmp;
    if (!ft_iseol(result))
    {
        while (!ft_iseol(result) && (reslen = read(fd, buffer, BUFFER_SIZE)) > 0)
        {
            
        }
    }
}

