#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

int	nl_find(char *buff)
{
	int	i;

	i = 0;
	while (buff && buff[i])
	{
		if (buff[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

void	update_buff(char *buff)
{
	int	i;
	int	j;

	i = 0;
	j = nl_find(buff);
	if (!j)
	{
		buff[0] = 0;
		return ;
	}
	while (buff[j])
	{
		buff[i] = buff[j];
		i++;
		j++;
	}
	buff[i] = 0;
	return ;
}

char	*nl_strjoin(char *line, char *buff)
{
	char	*new_line;
	int		i;
	int		j;

	if (!nl_find(buff))
		new_line = malloc(sizeof(char *) * (ft_strlen(line) + ft_strlen(buff) + 1));
	else
		new_line = malloc(sizeof(char *) * (ft_strlen(line) + nl_find(buff) + 1));
	i = 0;
	while (line && line[i])
	{
		new_line[i] = line[i];
		i++;
	}
	j = 0;
	while(buff[j] && buff[j] != '\n')
	{
		new_line[i] = buff[j];
		i++;
		j++;
	}
	if (buff[j] == '\n')
	{
		new_line[i] = buff[j];
		i++;
	}
	new_line[i] = 0;		
	return (new_line);
}

char	*get_next_line(int fd)
{
	static char buff[BUFFER_SIZE + 1];
	char 		*line;
	char		*tmp;
	int			r;

	if (read(fd, buff, 0) == -1)
		return (NULL);
	line = NULL;
	if (buff[0])
		line = nl_strjoin(line, buff); 
		
	while (!nl_find(buff))
	{
		r = read(fd, buff, BUFFER_SIZE);
		if (r == 0)
		{
			update_buff(buff);
			return (line);
		}
		buff[r] = 0;
		tmp = line;
		line = nl_strjoin(line, buff);
		free(tmp);
	}
	update_buff(buff);
	return (line);	
}
