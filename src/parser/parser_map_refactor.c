#include "../../includes/parser.h"

static	void	fill_new_map_extend(t_map *map,
	char **new_map_arr, int *y_x, int *n_y_x)
{
	while (map->map_arr[y_x[Y]][y_x[X]])
	{
		new_map_arr[n_y_x[Y]][n_y_x[X]] = map->map_arr[y_x[Y]][y_x[X]];
		y_x[X]++;
		n_y_x[X]++;
	}
	while (n_y_x[X] < map->map_width + 2)
		new_map_arr[n_y_x[Y]][n_y_x[X]++] = ' ';
}

static	char	**fill_new_map(t_map *map, char **new_map_arr)
{
	int	y_x[2];
	int	n_y_x[2];

	y_x[Y] = 0;
	n_y_x[Y] = 0;
	new_map_arr[n_y_x[Y]] = ft_memset(new_map_arr[n_y_x[0]],
			' ', map->map_width + 2);
	n_y_x[Y]++;
	while (map->map_arr[y_x[Y]] && (check_line(map->map_arr[y_x[Y]], NULL)
			|| map->map_arr[y_x[Y]][0] != '\0'))
	{
		y_x[X] = 0;
		n_y_x[X] = 0;
		new_map_arr[n_y_x[Y]][n_y_x[X]] = ' ';
		n_y_x[X]++;
		fill_new_map_extend(map, new_map_arr, y_x, n_y_x);
		y_x[Y]++;
		n_y_x[Y]++;
	}
	new_map_arr[n_y_x[Y]] = ft_memset(new_map_arr[n_y_x[Y]],
			' ', map->map_width + 2);
	gfree_arr((void **)map->map_arr);
	return (new_map_arr);
}

void	map_refactor(t_map *map)
{
	char	**new_map_arr;
	int		y;

	if (!map->map_arr)
		terminate_error("Error: Map not found");
	map->map_height = calc_map_height(map->map_arr);
	map->map_width = calc_map_width(map->map_arr);
	if (map->map_width < 3 && map->map_height < 3)
		terminate_error("Error: Map very little");
	new_map_arr = galloc((map->map_height + 3) * sizeof(char *));
	y = 0;
	while (map->map_height + 2 > y)
	{
		new_map_arr[y] = galloc((map->map_width + 3) * sizeof(char));
		new_map_arr[y][map->map_width + 2] = '\0';
		y++;
	}
	new_map_arr[y] = NULL;
	map->map_arr = fill_new_map(map, new_map_arr);
}
