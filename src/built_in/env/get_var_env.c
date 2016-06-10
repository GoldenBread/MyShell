/*
** get_var_env.c for 42sh in /tmp/PSU_2015_minishell2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat Jun  4 22:32:00 2016 Thierry LEVISSE
** Last update Sun Jun  5 01:57:21 2016 Thierry LEVISSE
*/

#include	<string.h>
#include	"parsing.h"

int	strcmp_varenv(char *search, char *s2)
{
  int	i;

  i = 0;
  while (search[i] != '\0' || s2[i] != '=')
    {
      if (search[i] != s2[i])
	return (1);
      i++;
    }
  return (0);
}

char	*getvarenv(char *var, char **arge)
{
  int	i;
  int	j;
  int	k;
  char	*str;

  i = 0;
  while (arge[i] != NULL && strcmp_varenv(var, arge[i]) != 0)
    i++;
  if (arge[i] == NULL)
    return (NULL);
  k = strlen(var) + 1;
  j = 0;
  str = my_xmalloc(strlen(arge[i]));
  while (arge[i][k] != '\0')
    {
      str[j] = arge[i][k];
      k++;
      j++;
    }
  str[j] = '\0';
  return (str);
}
