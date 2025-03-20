#include "../../includes/parser.h"

int	calc_map_height(char **map_arr)
{
	int	y;
	int	temp_y;
	int	flag;

	flag = 0;
	y = 0;
	while (map_arr[y] && !check_line(map_arr[y], NULL) && map_arr[y][0] != '\0')
		y++;
	flag = 1;
	temp_y = y;
	while (map_arr[temp_y])
	{
		if (!check_line(map_arr[temp_y], NULL) && map_arr[temp_y][0] != '\0')
			terminate_error("Error: Wrong map format");
		temp_y++;
	}
	return (y);
}

int	calc_map_width(char **map_arr)
{
	int	y;
	int	x;
	int	max_width;

	y = -1;
	max_width = 0;
	while (map_arr[++y])
	{
		x = -1;
		while (map_arr[y][++x])
			;
		if (max_width < x)
			max_width = x;
	}
	return (max_width);
}

int	char_in_set(char c, char *set)
{
	int	i;

	i = -1;
	while (set[++i])
	{
		if (set[i] == c)
			return (1);
	}
	return (0);
}

char	**dynamic_arr(char **arr, char *line)
{
	int		i;
	int		j;
	char	**new_arr;

	i = 0;
	if (!arr)
	{
		arr = galloc(2 * sizeof(char *));
		arr[0] = NULL;
		arr[1] = NULL;
	}
	while (arr[i])
		i++;
	new_arr = galloc((i + 2) * sizeof(char *));
	i = 0;
	j = 0;
	while (arr[i])
		new_arr[j++] = add_galloc(ft_strdup(arr[i++]));
	new_arr[j] = add_galloc(ft_strdup(line));
	new_arr[++j] = NULL;
	i = 0;
	gfree_arr((void **)arr);
	return (new_arr);
}
