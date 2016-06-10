/*
** strlen.c for 42sh in /home/thierry/Github/MyShell/src/string
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun 10 02:17:31 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:22:25 2016 Thierry LEVISSE
*/

#include	<stdio.h>

int		my_strlen(char *str)
{
  int		i;

  i = 0;
  if (!str)
    fprintf(stderr, "NULL\n");
  else
    {
      while (str[i] != '\0')
	i++;
    }
  return (i);
}
