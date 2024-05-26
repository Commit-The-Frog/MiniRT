#include "minirt.h"

void	exit_with_free(char **list)
{
	free_double_char_list(list);
	exit(1);
}

// verify one line that seperated with spaces
// if line is invalid, program exit with freeing every data
void	verify_line(char **list)
{

}