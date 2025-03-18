#ifndef PARSER_H
# define PARSER_H

# include "galloc.h"
# include "get_next_line.h"
#include "../libs/libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

# define NO 0
# define SO 1
# define WE 2
# define EA 3

typedef struct s_map
{
	char	*file_name;
	int		fd_file;
	char	**map_arr;
	char	**texture;
	int		*floor;
	int		*ceiling;
}	t_map;

//parser.c
t_map	*parser(char *file);

//parser_file.c
void	open_file(t_map *map);
void	read_file(t_map *map);
void	check_file_name(char *file_name);

//parser_utils.c
int	texture_check(char *line);
int	color_check(char *line);
int check_line(char *line);

//parer_map.c
void	map_parser(t_map *map);

//map_struct_parser.c
void	color_parser(char *line, t_map *map);
void	check_maps_args_extend(int *floor_ceiling);
void	texture_parser(char *line, t_map *map);
void	check_maps_args(t_map *map);

//init_map.c
t_map	*init_map(char *file);

#endif
