#include "../../includes/parser.h"

t_map	*init_map(char *file)
{
	int i;
	t_map *map;

	map = galloc(sizeof(t_map));
	map->file_name = file;

	map->fd_file = -1;

	map->map_arr = NULL;

	map->texture = galloc(5 * sizeof(char *));
	i = -1;
	while(++i < 5)
		map->texture[i] = NULL;
	map->floor = galloc(3 * sizeof(int *));
	i = -1;
	while (++i < 3)
		map->floor[i] = -1;

	map->ceiling = galloc(3 * sizeof(int *));
	i = -1;
	while (++i < 3)
		map->floor[i] = -1;
	return (map);
}
