/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin </var/mail/lanselin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:12:14 by lanselin          #+#    #+#             */
/*   Updated: 2020/12/21 20:12:17 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

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
