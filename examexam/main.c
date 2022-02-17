#include "get_next_line.h"

int main()
{
	int fd;
	char *line;

	fd = open("testfile", O_RDONLY);
	line = malloc(2);
	line = "a";

	while (line)
	{
		line = NULL;
		line = get_next_line(fd);
		printf("%s", line);
	}
	free(line);
	return 0;
}
