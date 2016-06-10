/*
** my_exit.c for exit it in /home/goutas_h/rendu/PSU_2015_42sh/src
** 
** Made by Hadrien GOUTAS
** Login   <goutas_h@epitech.net>
** 
** Started on Tue May 31 17:10:04 2016 Hadrien GOUTAS
** Last update Sun Jun  5 03:11:13 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<string.h>
#include	"shell.h"
#include	"string_cu.h"
#include	"parsing.h"

int	allstick(char **d_array)
{
  d_array[1] = d_array[0];
  strn_delay(d_array[1], 4);
  return (check_nbr(d_array[1]));
}

int	args_built_exit(char **d_array)
{
  if ((my_strcmp(d_array[0], "exit") == 0 || my_strcmp(d_array[0], "cd") == 0)
      && darray_len(d_array) > 2)
    {
      my_putstr_err("exit: Expression Syntax.\n");
      return (1);
    }
  return (0);
}

void	exit_quit(unsigned char nbr, char **arge)
{
  free_darray(arge);
  exit(nbr);
}

void	my_exit(char **cmd, t_data *data)
{
char	exit_state;

  if (args_built_exit(cmd) == 0)
    {
      exit_state = 0;
      if (cmd[1] == NULL && my_strlen(cmd[0]) == 4)
	{
	  my_putstr("exit\n");
	  exit_quit(0, data->env);
	}
      else if (cmd[1] == NULL && my_strlen(cmd[0]) > 4)
	exit_state = allstick(cmd);
      else
	exit_state = check_nbr(cmd[1]);
      if (cmd[1] != NULL && exit_state == 0)
	{
	  my_putstr("exit\n");
	  exit_quit(my_getnbr(cmd[1]), data->env);
	}
      else if (cmd[1] != NULL && exit_state == 1)
	my_putstr_err("exit: Badly formed number.\n");
      else if (cmd[1] != NULL && exit_state == 2)
	my_putstr_err("exit: Expression Syntax.\n");
    }
}
