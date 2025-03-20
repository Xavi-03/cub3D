#include "../../includes/parser.h"

//if (ft_strlen(map->map_arr[y]) <= x || ft_strlen(map->map_arr[y]) <= y)
//	;
int	open_map(t_map *map, int x, int y)
{
	if (0 >= x || 0 >= y)
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

void	player_pos(t_map *map, int x, int y, char c)
{
	static int	count_players = 0;

	count_players++;
	if (count_players > 1)
		terminate_error("Error: More than 1 player found");
	map->player_direction = c;
	map->x_player = x;
	map->y_player = y;
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
			if (char_in_set(map->map_arr[y][x], "0NWES") && open_map(map, x, y))
				terminate_error("Error: Map is open");
			if (!check_char(map, x, y))
				terminate_error("Error: Wrong char in map");
		}
	}
}
