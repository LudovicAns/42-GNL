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
# define BUFFER_SIZE 10

#include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_iseol(char *s);
char	*ft_empty_string(void);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_combine_result(char *result, char *buffer, int reslen);
int		ft_strlen(char *s, int eol);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
