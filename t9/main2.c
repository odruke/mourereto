#include <stdio.h>
#include <stdlib.h>
#include "libt9.h"

int	main()
{
	{
		char	*msg;
		char	*n;
		n = "6-66-666";
		msg = ft_t9(n);
		free(msg);
		printf("%s", msg);
	}
}
