#include "../../includes/parser.h"

void	color_parser(char *line, t_map *map)
{
	int		i;
	int		fd;
	char	**line_splited;
	int		*number_arr;

	i = 1;
	while (line[i] == ' ')
		i++;
	line_splited = add_galloc_arr((void **)ft_split(&line[i], ','));
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && line[i] != ',')
		{
			ft_putendl_fd("Error: Ceiling or Floor wrong arguments", 2);
			terminate(1);
		}
		i++;
	}
	if (color_check(line) == 1)
		number_arr = map->floor;
	else if (color_check(line) == 2)
		number_arr = map->ceiling;
	number_arr[0] = ft_atoi(line_splited[0]);
	number_arr[1] = ft_atoi(line_splited[1]);
	number_arr[2] = ft_atoi(line_splited[2]);
}

void	texture_parser(char *line, t_map *map)
{
	int i;
	int fd;

	if(ft_strncmp(ft_strrchr(line, '.'), ".xpm", 5) != 0)
	{
		ft_putendl_fd("Error: Wrong file extension", 2);
		terminate(1);
	}
	i = 2;
	while (line[i] == ' ')
		i++;
	map->texture[texture_check(line) - 1] = add_galloc(ft_strdup(&line[i]));
	fd = open(map->texture[texture_check(line) - 1], O_RDONLY);
	if (fd == -1)
	{
		ft_putendl_fd("Error: Can't open the file texture", 2);
		terminate(1);
	}
	close(fd);
}

void	check_maps_args_extend(int *floor_ceiling)
{
	int	i;

	i = 0;
	while (i < 3 && floor_ceiling[i] != -1)
	{
		if (floor_ceiling[i] >= 256)
		{
			ft_putendl_fd("Error: Wrong floor number", 2);
			terminate(1);
		}
		i++;
	}
	if (i != 3)
	{
		ft_putendl_fd("Error: Not found 3 number in ceiling", 2);
		terminate(1);
	}
}

//check if is the map struct is complete
void	check_maps_args(t_map *map)
{
	int	i;

	i = -1;
	while (map->texture[++i])
		;
	if (i != 4)
	{
		ft_putendl_fd("Error: Not found 4 textures", 2);
		terminate(1);
	}
	//check if direction repeat in texture string
	check_maps_args_extend(map->floor);
	check_maps_args_extend(map->ceiling);
}
