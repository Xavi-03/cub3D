#ifndef PARSER_H
# define PARSER_H

# include "galloc.h"
# include "get_next_line.h"
# include <unistd.h>
# include <fcntl.h>

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

//init_map.c
t_map	*init_map(char *file);

#endif
