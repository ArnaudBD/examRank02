#include "get_next_line.h"
#include <unistd.h>
#define BUFFER_SIZE 5

int strlen(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		i++;
	}
	return i;
}


strjoin(char * s1, char *s2)
{
	int i;
	int j;
	int len1;
	int len2;
	int len;
	char *str;

	len1 = strlen(s1);
	len2 = strlen(s2);
	len = len1 + len2;
	str = malloc(sizeof(char *) * len + 1);
	str[len] = 0;
	i = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		str[i] = s2[j];
		j++;
	}
	free(s1);
	return str;
}

char *buff(char *buff)
{
	int i;
	char *str;

	len = strlen(buff);
	str = malloc(sizeof(char *) * (len + BUFFER_SIZE) + 1);
	i = 0;
	while (i <= len)
	{
		str[i] = buff[i];
		i++;
	}
	return str;
}

char *get_next_line(int fd)
{
	static char *buff;
	char *line;
	char *tmp;
	int i;
	int j;

	tmp = malloc(sizeof(char *) * BUFFER_SIZE + 2);
	buff = malloc(sizeof(char *) * BUFFER_SIZE + 2);
	if (fd < 0 || !buff)
		return NULL;
	buff[BUFFER_SIZE + 1] = 0;
	while (read(1, buff, BUFFER_SIZE) == BUFFER_SIZE)
	{
		strjoin(line, buff);
		i = 0;
		while(buff[i] != 0)
		{
			line[i] = buff[i];
			if (buff[i] == '\n')
			{
				i++;
				j = 0;
				while (buff[i])
				{
					tmp[j] = buff[i];
					i++;
					j++;
				}
				tmp[j] = buff[i];
				free(tmp);
				return line;
			}
			i++;
		}
		buff = addspace(buff);
	}
	while(buff[i])
	{
		line[i] = buff[i];
		i++;
	}
	free(buff);
	return line;
}
