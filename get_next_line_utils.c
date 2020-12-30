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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*str;

	if (!s1 || !s2)
		return (0);
	if (!(str = (char *)malloc((ft_strlen(s1, 0) + ft_strlen(s2, 0))
					* sizeof(char) + 1)))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	*ft_combine_result(char *result, char *buffer, int reslen)
{
	char	*temp;
	char	*newstr;

	temp = result;
	buffer[reslen] = '\0';
	newstr = ft_strjoin(result, buffer);
	free(temp);
	return (newstr);
}

int		ft_strlen(char *s, int eol)
{
	int		i;

	i = 0;
	if (!s)
		return (0);
	if (eol == 1)
	{
		while (s[i] && s[i] != '\n')
			i++;
	}
	else if (eol == 0)
	{
		while (s[i])
			i++;
	}
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*out;

	if (!s)
		return (NULL);
	size = ft_strlen(s, 0) - start;
	size = len > size ? size : len;
	if (start > ft_strlen(s, 0))
		size = 0;
	if (!(out = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	i = 0;
	while (i < size)
		out[i++] = s[start++];
	out[i] = '\0';
	return (out);
}
