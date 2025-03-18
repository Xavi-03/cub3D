# include "../../includes/parser.h"

int	open_map(t_map *map, int x, int y)
{
	if (ft_strlen(map->map_arr[y]) <= x || ft_strlen(map->map_arr[y]) <= y)
		;
	else if (0 >= x || 0 >= y)
		;
	else if (map->map_arr[y + 1][x] == ' ')
		;
	else if (map->map_arr[y - 1][x] == ' ')
		;
	else if (map->map_arr[y][x + 1] == ' ')
		;
	else if (map->map_arr[y][x - 1] == ' ')
		;
	else
		return (0);
	return (1);
}

int	check_char(t_map *map, int x, int y)
{
	if (map->map_arr[y][x] == '0')
		;
	else if (map->map_arr[y][x] == '1')
		;
	else if (map->map_arr[y][x] == 'N')
		;
	else if (map->map_arr[y][x] == 'E')
		;
	else if (map->map_arr[y][x] == 'S')
		;
	else if (map->map_arr[y][x] == 'W')
		;
	else if (map->map_arr[y][x] == ' ')
		;
	else
		return (0);
	return (1);
}

void	map_parser(t_map *map)
{
	int	y;
	int	x;

	y = -1;
	x = -1;
	while (map->map_arr[++y])
	{
		x = -1;
		while (map->map_arr[y][++x])
		{
			if (map->map_arr[y][x] == '0' && open_map(map, x, y))
			{
				ft_putendl_fd("Error: Map is open", 2);
				terminate(1);
			}
			if (!check_char(map, x, y))
			{
				printf("%c\n", map->map_arr[y][x]);
				ft_putendl_fd("Error: Wrong char in map", 2);
				terminate(1);
			}
		}
	}
}
