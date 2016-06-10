/*
** putstr.c for 42sh in /home/thierry/Github/MyShell/src/string
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun 10 02:17:22 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:22:07 2016 Thierry LEVISSE
*/

#include	<unistd.h>
#include	<stdio.h>

void		my_putstr(char *str)
{
  int		i;

  i = 0;
  if (!str)
    fprintf(stderr, "NULL\n");
  else
    {
      while (str[i] != '\0')
	i++;
      write(1, str, i);
    }
}

void		my_putstr_err(char *str)
{
  int		i;

  i = 0;
  if (!str)
    fprintf(stderr, "NULL\n");
  else
    {
      while (str[i] != '\0')
	i++;
      write(2, str, i);
    }
}
