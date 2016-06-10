/*
** strcat.c for 42sh in /home/thierry/Github/MyShell/src/string
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun 10 02:27:21 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:27:22 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"string_cu.h"

void	my_strcat(char *dest, char *src)
{
  int	i;
  int	j;

  i = 0;
  j = my_strlen(dest);
  while (src[i] != 0)
    {
      dest[j + i] = src[i];
      i++;
    }
  dest[j + i] = '\0';
}
