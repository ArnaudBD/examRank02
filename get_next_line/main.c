#include "get_next_line.h"

int main()
{
	int fd;
	char *line;	

	line = "hello";
	fd = open("testfile.txt", O_RDONLY);

	while (line)
	{
		line = get_next_line(fd);
		printf("%s",line);
		free(line);
	}
}