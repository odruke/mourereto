#include <string.h>
#include "libt9.h"

char	equal(char *str)
{
	int	i;
	int	n;
	char	*tecla;
	char	*cero= " ";
	char	*uno= ".,!?";
	char	*dos = "ABC";
	char	*tres = "DEF";
	char	*cuatro = "GHI";
	char	*cinco = "JKL";
	char	*seis = "MNO";
	char	*siete = "PQRS";
	char	*ocho = "TUV";
	char	*nueve = "WXYZ";

	switch (str[0])
	{

		case '0':
			tecla = cero;
			break;
		case '1':
			tecla = uno;
			break;
		case '2':
			tecla = dos;
			break;
		case '3':
			tecla = tres;
			break;
		case '4':
			tecla = cuatro;
			break;
		case '5':
			tecla = cinco;
			break;
		case '6':
			tecla = seis;
			break;
		case '7':
			tecla = siete;
			break;
		case '8':
			tecla = ocho;
			break;
		case '9':
			tecla = nueve;
			break;
	}
	
	i = -1;
	n = strlen(str);
	while (n > 0)
	{
		i++;
		n--;
		if(!tecla[i])
			i = 0;
	}
	return (tecla[i]);
}
