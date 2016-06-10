/*
** echo.c for echo in /home/kania_r/rendu/PSU/my_echo
** 
** Made by Romain KANIA
** Login   <kania_r@epitech.net>
** 
** Started on Tue May 31 12:52:55 2016 Romain KANIA
** Last update Sun Jun  5 14:52:47 2016 Romain KANIA
*/

#include	<string.h>
#include	<stdlib.h>
#include	<unistd.h>
#include	"string_cu.h"
#include	"shell.h"

int		checknbrquote(char **tab)
{
  int		x;
  int		y;
  int		nb;

  nb = 0;
  x = 0;
  y = 1;
  while (tab[y])
    {
      while (tab[y][x])
	{
	  if (tab[y][x] == '\"')
	    nb++;
	  x++;
	}
      y++;
      x = 0;
    }
  return (nb % 2);
}

void		checkbackslash(char c, int echo, t_data *data)
{
  int		i;

  if (c < 14 && c > 6 && echo == 1)
    write(1, &c, 1);
  else if (c < 14 && c > 6 && echo == 0)
    {
      i = c - 7;
      write(1, &data->sign[i], 1);
    }
  else
    write(1, &c, 1);
}

void		disp(char **tab, t_data *data, int mode)
{
  int		y;

  if (mode == 1)
    y = 2;
  else
    y = 1;
  while (tab[y])
    {
      echo_disp_loop(tab, data, y);
      if (y < darray_len(tab) - 1)
	my_putchar(' ');
      y++;
    }
  if (mode == 0)
    write(1, "\n", 1);
}

void		my_echo(char **tab, t_data *data)
{
  int		nb;

  tab = data->echo_cmd;
  if (tab[1] == NULL)
    write(1, "\n", 1);
  else
    {
      if (strcmp(tab[1], "-n\0") == 0)
	nb = 1;
      else
	nb = 0;
      if (checknbrquote(tab) == 0 && nb == 0)
	disp(tab, data, 0);
      else if (checknbrquote(tab) == 0 && nb == 1)
	disp(tab, data, 1);
      else
	write(2, "Unmatched .\"\n", 14);
    }
}

void		init_echo(t_data *data)
{
  data->echo = 0;
  strcpy(data->sign, "abtnvfr");
}
