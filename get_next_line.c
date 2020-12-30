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
            result = ft_combine_result(result, buffer, reslen);
        }
    }
    if (ft_iseol(result) || reslen < BUFFER_SIZE)
    {
        free(buffer);
        return (return_result(result, line, &tmp, reslen));
    }
    return (-1);
}

int     return_result(char *result, char **line, char **tmp, int reslen)
{
    int     size;

    if (reslen <= -1)
        return (-1);
    if (reslen == 0 && !ft_iseol(result))
    {
        *line = result;
        tmp = NULL;
        return (0); // Fin de fichier
    }
    if (!ft_iseol(result))
    {
        *line = result;
        return (1); // reslen > 0, Une ligne (sans \n a été trouvé)
    }
    size = ft_strlen(result, 0) - (ft_strlen(result, 1) + 1);
    *line = ft_substr(result, 0, ft_strlen(result, 1));
    *tmp = ft_substr(result, ft_strlen(result, 1) + 1, size);
    result = NULL;
    free(result);
    return (1);
}

