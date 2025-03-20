#include "../../includes/parser.h"

char	**map_replace(char **map_arr)
{
	int	y;
	int	x;

	y = -1;
	while (map_arr[++y])
	{
		x = -1;
		while (map_arr[y][++x])
		{
			if (map_arr[y][x] == ' ')
				map_arr[y][x] = '1';
		}
	}
	return (map_arr);
}

t_map	*parser(char *file)
{
	int		fd;
	t_map	*map;

	map = init_map(file);
	open_file(map);
	read_file(map);
	map_refactor(map);
	map_parser(map);
	check_player(map);
	map->map_arr = map_replace(map->map_arr);
	return (map);
}
/*
printf("check\n");
	printf("%s\n", map->file_name);
	printf("%i\n", map->fd_file);
	int i = -1;
	while (map->map_arr && map->map_arr[++i])
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


i = -1;
	while (map->map_arr && map->map_arr[++i])
		printf("%s\n", map->map_arr[i]);
	printf("end map\n");
*/
