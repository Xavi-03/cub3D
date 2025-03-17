#include "../../includes/galloc.h"

void	*add_galloc_arr(void **mem)
{
	void	**temp_mem;

	temp_mem = mem;
	add_galloc(temp_mem);
	while(*temp_mem)
	{
		add_galloc(*temp_mem);
		temp_mem++;
	}
	return (mem);
}
