#include "../../includes/parser.h"



t_map	*parser(char *file)
{
	int fd;

	t_map *map;
	map = init_map(file);
	open_file(map);
	read_file(map);
	return (map);
}
