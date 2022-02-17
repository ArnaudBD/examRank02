#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>

char *get_next_line(int fd);
int ft_strlen(char *str);
int nl_find(char *buff);
void reset_buff(char *buff);
char *nl_strjoin(char *line, char *buff);

#endif
