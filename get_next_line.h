/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:13:01 by lanselin          #+#    #+#             */
/*   Updated: 2021/02/05 14:13:02 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int		get_next_line(int fd, char **line);
int		ft_iseol(char *s);
char	*ft_empty_string(void);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_combine_result(char *result, char *buffer, int reslen);
int		ft_strlen(char *s, int eol);
char	*ft_substr(char *s, int start, size_t len);
int		get_next_line(int fd, char **line);
int     return_result(char *result, char **line, char **tmp, int reslen);

#endif
