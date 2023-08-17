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
		if ((str[i] > '1' && str[i] <= '9') || str[i] == '-')
			i++;
		else if (str[i] == '-')
			n++;
		else
			return(0);
	}
	return (1);
}

static int	setblock(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	while (src[i] && src[i] != '-')
		i++;
	len = i;
	dest = (char *)malloc(sizeof(char) * len + 1);
	if (!dest)
		return(0);
	i = 0;
	while (src[i] && src[i] != '-')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	i--;
	if (i > 1)
	{
		while (i > 0)
		{
			if (src[i] != dest[i])
				return (-1);
			i--;
		}
	}
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
	len = strlen(str);
	if (!(msglen = checkvalidinput(str)))
	{
		printf("invalid input, only numbers between the symbol - accepted");
		return (NULL);
	}
	msg = (char *)malloc(sizeof(char) * msglen);
		if (!msg)
			return (NULL);
	while (str[i])
	{
		if (str[i] != '-')
		{
			i = setblock(block, str + i);
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
