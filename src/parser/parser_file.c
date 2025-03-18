#include "../../includes/parser.h"

void	check_file_name(char *file_name)
{
	int	i;

	i = -1;
	while(file_name[++i])
	{
		if (file_name[i] == ' ')
		{
			ft_putendl_fd("Error: File name not accepted", 2);
			terminate(1);
		}
	}
	if (ft_strncmp(ft_strrchr(file_name, '.'), ".cub", 5) != 0)
	{
		ft_putendl_fd("Error: Wrong file extension", 2);
		terminate(1);
	}
}

void	open_file(t_map *map)
{
	int	fd;

	check_file_name(map->file_name);
	map->fd_file = open(map->file_name, O_RDONLY);
	if (map->fd_file == -1)
	{
		ft_putendl_fd("Error: Can't open file", 2);
		terminate(1);
	}
}

char **dynamic_arr(char **arr, char *line)
{
	int 	i;
	int		j;
	char	**new_arr;

	i = 0;
	if (!arr)
	{
		arr = galloc(2 * sizeof(char *));
		arr[0] = NULL;
		arr[1] = NULL;
	}
	while (arr[i])// iteri the first arr for alloc second arr with 1 extra arr and copy and return
		i++;
	new_arr = galloc((i + 2) * sizeof(char *));
	i = 0;
	j = 0;
	while (arr[i])
	{
		new_arr[j] = add_galloc(ft_strdup(arr[i]));
		i++;
		j++;
	}
	new_arr[j] = add_galloc(ft_strdup(line));
	new_arr[++j] = NULL;
	i = 0;
	while (arr[i]) //maybe implement a gfree_arr
	{
		if (arr[i])
			gfree(arr[i++]);
	}
	gfree(arr);
	return (new_arr);
}

void	read_all_file(char *line, t_map *map)
{
	line = ft_strdup(line);
	while (line)
	{
		if (line[0] != '\n')
		{
			add_galloc(line);
			line = add_galloc(ft_strtrim(line, "\n"));
			map->map_arr = dynamic_arr(map->map_arr, line);
		}
		gfree(line);
		line = get_next_line(map->fd_file);
	}
	close(map->fd_file);
}

void	read_file(t_map *map)
{
	char *line;
	while (true)
	{
		line = get_next_line(map->fd_file);
		if (!line)
			break;
		if (line[0] == '\n' || check_line(line))
		{
			free(line);
			continue ;
		}
		add_galloc(line);
		line = add_galloc(ft_strtrim(line, "\n"));
		if (texture_check(line))
			texture_parser(line, map);
		else if (ft_strncmp(line, "F ", 2) == 0 || ft_strncmp(line, "C ", 2) == 0)
			color_parser(line, map);
		else
		{
			check_maps_args(map);
			read_all_file(line, map);
			return ;
		}
		gfree(line);
	}
}
