/*
** echo_loop.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jun  5 03:57:17 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:28:27 2016 Hadrien GOUTAS
*/

#include	<stdlib.h>
#include	"string_cu.h"
#include	"shell.h"

void	echo_disp_loop(char **tab, t_data *data, int y)
{
  int	x;

  x = 0;
  while (tab[y][x])
    {
      if (tab[y][x] == 34 && data->echo == 0)
	data->echo = 1;
      else if (tab[y][x] == 34 && data->echo == 1)
	data->echo = 0;
      else
	checkbackslash(tab[y][x], data->echo, data);
      x++;
    }
}

void	echo_loop(t_data *data, char *cmd_str)
{
  char	*duped;
  char	*tmp;

  if (cmd_str)
    {
      duped = my_strdup(cmd_str);
      tmp = epur_quote(duped);
      data->echo_cmd = my_quote_to_wordtab(tmp);
    }
  if (tmp)
    free(tmp);
}
