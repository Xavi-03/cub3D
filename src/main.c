#include "../includes/galloc.h"
#include "../includes/parser.h"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_putendl_fd("Error: Waiting 2 arguments", 2);
		exit (1);
	}
	init_galloc();
	parser(argv[1]);
	free_galloc(NULL);
}
