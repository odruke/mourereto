#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "libt9.h"

static int	checkvalidinput(char *str)
{
	int	i;
	int	n;

	i = 0; 
	n = 0;
	if (!isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9') || str[i] == '-')
			i++;
		else
			return (0);
		if ((isdigit(str[i]) && isdigit(str[i - 1])) && (str[i] != str[i - 1]))
			return (0);
		if (str[i] == '-' && str[i - 1] == '-')
			return (0);
	}
	if (str[i - 1] == '-')
		return (0);
	return (1);
}

static int	msgsize(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 1;
	while (str[i])
	{
		if(str[i] == '-')
			n++;
		i++;
	}
	return (n);
}

static int	setblock(char **dest, const char *src)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
//	len = (strchr(src, '-') - src);
	while (src[len] != '-')
		len++;
	*dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!*dest)
		return(0);
	while (src[i] && (src[i] != '-'))
	{
		(*dest)[i] = src[i];
		i++;
	}
	(*dest)[i] = '\0';
	return (len + 1);
}

char	*ft_t9(char *str)
{
	int	i;
	int	n;
	int	len;
	int	msglen;
	char	*block;
	char	*msg;

	i = 0;
	n = 0;
	if (!checkvalidinput(str))
	{
		printf("invalid input:\n-only numbers\n-block numbers must be the same number\n-block separator must be '-' character\n-last character must be a number\n\n");
		return (NULL);
	}
	len = strlen(str);
	msglen = msgsize(str);
	msg = (char *)malloc(sizeof(char) * (msglen + 1));
		if (!msg)
			return (NULL);
	while (i < len)
	{
		if (str[i] != '-')
		{
			i += setblock(&block, str + i);
			if (i < 0)
			{
				printf("numbers in blocks must be equal");
				free(msg);
				free(block);
				return (NULL);
			}
			msg[n] = equal(block);
			n++;
			free(block);
		}
	}
	msg[n] = '\0';
	return (msg);
}
