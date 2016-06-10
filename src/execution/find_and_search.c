/*
** find_and_search.c for R & D in /home/goutas_h/rendu/PSU_2015_42sh
** 
** Made by Hadrien GOUTAS
** Login   <goutas_h@epitech.net>
** 
** Started on Sun Jun  5 13:45:41 2016 Hadrien GOUTAS
** Last update Sun Jun  5 13:46:23 2016 Hadrien GOUTAS
*/

#include	<string.h>

int	searchslash(char *command)
{
  int	i;

  i = 0;
  if (command[0] == '.' && command[1] == '/')
    return (2);
  while (command[i])
    {
      if (command[i] == '/' && (i == 0 || command[i - 1] != '.'))
	return (1);
      i++;
    }
  return (0);
}

int	findvar(char **env, char *var)
{
  int	i;

  i = 0;
  while (env[i])
    {
      if (strncmp(var, env[i], 5) == 0)
	return (i);
      i++;
    }
  return (-1);
}
