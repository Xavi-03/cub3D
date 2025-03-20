#include "../../includes/parser.h"

int	texture_check(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return (1);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return (2);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return (3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return (4);
	else
		return (0);
}

int	color_check(char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (2);
	else
		return (0);
}

int	check_line(char *line, int *spaces_count)
{
	int	i;

	i = 0;
	if (spaces_count)
		*spaces_count = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return (1);
	if (spaces_count)
		*spaces_count = i;
	return (0);
}

int	check_char(t_map *map, int x, int y)
{
	if (map->map_arr[y][x] == '0')
		;
	else if (map->map_arr[y][x] == '1')
		;
	else if (map->map_arr[y][x] == 'N')
		player_pos(map, x, y, 'N');
	else if (map->map_arr[y][x] == 'E')
		player_pos(map, x, y, 'E');
	else if (map->map_arr[y][x] == 'S')
		player_pos(map, x, y, 'S');
	else if (map->map_arr[y][x] == 'W')
		player_pos(map, x, y, 'W');
	else if (map->map_arr[y][x] == ' ')
		;
	else
		return (0);
	return (1);
}

void	check_player(t_map *map)
{
	if (map->player_direction == '\0')
		terminate_error("Error: player not found");
}
