#include <stdio.h>
#include <stdlib.h>
#include "libt9.h"

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		char	*msg;
		msg = ft_t9(av[1]);
		if(!msg)
		{
			printf("failed\n");
			return (0);
		}
		printf("%s\n", msg);
		free(msg);
	}
	return (0);
}
