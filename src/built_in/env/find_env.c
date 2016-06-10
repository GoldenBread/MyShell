/*
** find_env.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh/env
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Tue May 31 15:27:21 2016 Thierry LEVISSE
** Last update Sun Jun  5 02:52:12 2016 Thierry LEVISSE
*/

#include	<string.h>
#include	"shell.h"
#include	"string_cu.h"
#include	"parsing.h"

int	cpy_env_to_find(char **env, char *line, int j)
{
  int   i;
  int   check;
  char  *str;

  i = 0;
  check = 0;
  str = my_xmalloc(strlen(env[j]) + 1);
  while (env[j][i] && env[j][i] != '=')
    {
      str[i] = env[j][i];
      i++;
    }
  str[i] = '\0';
  if (env[j][i] == '=')
    check = strcmp(str, line);
  free(str);
  return (check);
}

int	find_env(char *line, char **env)
{
  int   j;
  int   check;

  j = 0;
  check = -1;
  while (check != 0 && env[j] != NULL)
    {
      check = cpy_env_to_find(env, line, j);
      j++;
    }
  if (env[j] == NULL && check != 0)
    return (-1);
  return (j - 1);
}
