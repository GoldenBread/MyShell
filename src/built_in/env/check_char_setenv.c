/*
** check_char_setenv.c for chekc_char_env in /home/wanty_w/rendu/PSU_2015_42sh/src/env
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Fri Jun  3 14:57:28 2016 William WANTY
** Last update Sun Jun  5 02:51:33 2016 Thierry LEVISSE
*/

#include <stdio.h>

int	check_char_setenv(char **cmd_tab)
{
  int	i;

  i = 0;
  if ((cmd_tab[1][0] < 'A' || cmd_tab[1][0] > 'Z') &&
      (cmd_tab[1][0] < 'a' || cmd_tab[1][0] > 'z'))
    {
      fprintf(stderr, "setenv: Variable name must begin with a letter.\n");
      return (-1);
    }
  while (cmd_tab[1][i] != '\0')
    {
      if ((cmd_tab[1][i] < '0' || cmd_tab[1][i] > '9') &&
	  (cmd_tab[1][i] < 'A' || cmd_tab[1][i] > 'Z') &&
	  (cmd_tab[1][i] < 'a' || cmd_tab[1][i] > 'z'))
	{
	  fprintf(stderr, "setenv: Variable name must ");
	  fprintf(stderr, "contain alphanumeric characters.\n");
	  return (-1);
	}
      i++;
    }
  return (0);
}
