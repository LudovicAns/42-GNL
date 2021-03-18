#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int		get_next_line(int fd, char **line);
int		iseol(char *s);
char	*ft_empty_string(void);
char	*ft_strjoin(char *s1, char *s2);
char	*combine(char *res, char *buffer, int reslen);
int		ft_strlen(char *s, int eol);
char	*ft_substr(char *s, int start, size_t len);
int		get_next_line(int fd, char **line);
int     return_result(char *res, char **line, char **tmp, int reslen);
char	*ft_strdup(char *s);
int     process_read(int fd, char **buffer, char **res);
void	secure_free(char **ptr);

#endif