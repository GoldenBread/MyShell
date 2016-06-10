/*
** get_env.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh/env
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Tue May 31 15:31:29 2016 Thierry LEVISSE
** Last update Fri Jun  3 16:45:28 2016 Romain KANIA
*/

#include	<string.h>
#include	"parsing.h"

char	*get_env(char *var_env)
{
  int	i;
  int	j;
  char	*ret;

  i = 0;
  while (var_env[i] && var_env[i] != '=')
    {
      i++;
    }
  ret = my_xmalloc(strlen(var_env) - i + 1);
  j = 0;
  i++;
  while (var_env[i])
    {
      ret[j] = var_env[i];
      i++;
      j++;
    }
  ret[j] = '\0';
  return (ret);
}
