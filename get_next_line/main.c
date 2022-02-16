#include "get_next_line.h"

int main()
{
	// int		fd;
	char	*line;
	// int		i;

	// i = 0;
	line = malloc(2);
	line[0] = 'a';
	line[1] = 0;
	// fd = open("testfile.txt", O_RDONLY);
	while (line)
	{
		free(line);
		line = get_next_line(1/*fd*/);
		printf("%s", line);
	}
	free(line);
}
