/*
** string5.c for minishell2 in /home/thierry/Rendu/PSU_2015_minishell2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Apr 10 12:30:58 2016 Thierry LEVISSE
** Last update Sat Jun  4 20:13:57 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<string.h>
#include	"parsing.h"

void	strn_delay(char *str, int n)
{
  int   i;

  i = 0;
  while (str[i + n] != '\0')
    {
      str[i] = str[i + n];
      i++;
    }
  str[i] = '\0';
}

char	*my_strndup(char *src, int n)
{
  int	i;
  char	*dest;

  dest = my_xmalloc(strlen(src) + 1);
  i = 0;
  while (src[i + n] != '\0')
    {
      src[i] = src[i + n];
      i++;
    }
  src[i] = '\0';
  strcpy(dest, src);
  return (dest);
}
