#include <stdio.h>
#include "libt9.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		char	*msg;
		msg = ft_t9(av[1]);
		printf("%s", msg);
	}
}
