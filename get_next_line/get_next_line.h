#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>

char	*get_next_line(int fd);
void	update_buff(char *buff);
int		nl_find(char *buff);
int		ft_strlen(char *s);
char	*nl_strjoin(char *s1, char *s2);

#endif
