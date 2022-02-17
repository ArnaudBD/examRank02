#include "get_next_line.h"

int main()
{
	int		fd;
	char	*line;

	line = malloc(2);
	line[0] = 'a';
	line[1] = 0;
	fd = open("longfile", O_RDONLY);
	while (line)
	{
		free(line);
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
}
