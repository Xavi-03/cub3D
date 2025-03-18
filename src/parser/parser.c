#include "../../includes/parser.h"


t_map	*parser(char *file)
{
	int fd;

	t_map *map;
	map = init_map(file);
	open_file(map);
	read_file(map);
	printf("check\n");
	printf("%s\n", map->file_name);
	printf("%i\n", map->fd_file);
	int i = -1;
	while (map->map_arr[++i])
		printf("%s\n", map->map_arr[i]);
	printf("end map\n");
	i = -1;
	while (map->texture[++i])
		printf("%s\n", map->texture[i]);
	printf("%i\n", map->floor[0]);
	printf("%i\n", map->floor[1]);
	printf("%i\n", map->floor[2]);
	printf("%i\n", map->ceiling[0]);
	printf("%i\n", map->ceiling[1]);
	printf("%i\n", map->ceiling[2]);

	map_parser(map);

	return (map);
}
