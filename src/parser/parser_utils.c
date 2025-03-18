#include "../../includes/parser.h"

int	texture_check(char *line)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		return(1);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		return(2);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		return(3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		return(4);
	else
		return (0);
}

int	color_check(char *line)
{
	if (ft_strncmp(line, "F ", 2) == 0)
		return (1);
	else if (ft_strncmp(line, "C ", 2) == 0)
		return(2);
	else
		return (0);
}

int check_line(char *line)
{
	int i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\n')
		return(1);
	return (0);
}
