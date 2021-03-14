/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utlis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanselin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 14:13:36 by lanselin          #+#    #+#             */
/*   Updated: 2021/02/05 14:13:38 by lanselin         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined_str;
	int		index;

	if (!(joined_str = (char *) malloc(sizeof(char) * 
		(ft_strlen(s1, 0) + ft_strlen(s2, 0) + 1))))
		return (NULL);
	index = 0;
	while (*s1)
	{
		joined_str[index] = *s1++;
		index++;
	}
	while (*s2)
	{
		joined_str[index] = *s2++;
		index++;
	}
	joined_str[index] = '\0';
	return(joined_str);
}

int	ft_strlen(char *s, int eol)
{
	int count;

	count = 0;
	if (eol)
	{
		while (s[count] && s[count] != '\n')
            count++;
	}
	else
	{
		while (s[count])
			count++;
	}
	return count;
}

int		has_eol(char *s)
{
	if (!s || !s[0])
		return (0);
	while (*s)
	{
		if (*s == '\n')
			return (1);
		s++;
	}
	return (0);
}

char	*empty_str()
{
	char *ptr;

	if (!(ptr = (char *)malloc(sizeof(char) * 1)))
		return (NULL);
	ptr[0] = '\0';
	return (ptr);
}

char	*extract_str(int start_index, int stop_index, char *s)
{
	char	*extracted_str;
	int		index;
	int		i;

	if (!s || !s[0])
		return (NULL);
	if (!(extracted_str = (char *)malloc(sizeof(char) 
		* ((stop_index + 1) - start_index + 1))))
		return (NULL);
	i = 0;
	index = 0;
	while (i < stop_index + 1)
	{
		if (i >= start_index && s[i])
			extracted_str[index++] = s[i];
			
		i++;
	}
	extracted_str[index] = '\0';
	return (extracted_str);
}
