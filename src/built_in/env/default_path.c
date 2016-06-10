/*
** echo.c for echo in /home/kania_r/rendu/PSU/my_echo
** 
** Made by Romain KANIA
** Login   <kania_r@epitech.net>
** 
** Started on Tue Jun 3 12:52:55 2016 Romain KANIA
** Last update Sun Jun  5 13:40:29 2016 Hadrien GOUTAS
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	"parsing.h"
#include	"shell.h"

int		varexist(char *var, char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if (strncmp(var, env[i], strlen(var)) == 0)
	return (0);
      i++;
    }
  return (1);
}

void		put_default_path(t_data *data)
{
  int		i;
  char		*pathbuf;
  size_t	n;
  char		*cmd[4];

  i = 0;
  n = confstr(_CS_PATH, NULL, (size_t) 0);
  pathbuf = my_xmalloc(sizeof(char) * (n + 1));
  if (pathbuf == NULL)
    exit(EXIT_FAILURE);
  confstr(_CS_PATH, pathbuf, n);
  cmd[0] = strdup("setenv");
  cmd[1] = strdup("PATH");
  cmd[2] = pathbuf;
  cmd[3] = NULL;
  my_setenv(cmd, data);
  i = 0;
  while (i < 3)
    {
      free(cmd[i]);
      i++;
    }
}
