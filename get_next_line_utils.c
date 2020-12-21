/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin </var/mail/lanselin>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/21 20:11:59 by lanselin          #+#    #+#             */
/*   Updated: 2020/12/21 20:12:00 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_iseol(char *s)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_empty_string(void)
{
	char *s;

	if (!(s = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	s[0]= '\0';
	return (s);
}
