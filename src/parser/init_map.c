#include "../../includes/parser.h"

t_map	*init_map(char *file)
{
	t_map *map;
	map = galloc(sizeof(t_map));
	map->file_name = file;
	map->fd_file = -1;
	map->map_arr = NULL;
	map->texture = NULL;
	map->floor = NULL;
	map->ceiling = NULL;
	return (map);
}
