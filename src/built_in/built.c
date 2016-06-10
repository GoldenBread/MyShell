/*
** built.c for built in /home/wanty_w/rendu/PSU_2015_42sh/src
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Thu Jun  2 15:00:41 2016 William WANTY
** Last update Sun Jun  5 10:25:22 2016 Hadrien GOUTAS
*/

#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	"parse_tree.h"
#include	"shell.h"

int		built_launch(char **command, t_data *data)
{
  int		i;

  i = 0;
  while (i < 5)
    {
      if (command && strcmp(data->builtins[i].built_in, command[0]) == 0)
	{
	  data->builtins[i].p(command, data);
	  return (0);
	}
      i++;
    }
  return (1);
}

int	built_check(char **command)
{
  char	*built[5];
  int	i;

  built[0] = strdup("setenv");
  built[1] = strdup("unsetenv");
  built[2] = strdup("exit");
  built[3] = strdup("echo");
  built[4] = strdup("cd");
  i = 0;
  while (command && i < 5)
    {
      if (strcmp(built[i], command[0]) == 0)
	return (0);
      free(built[i]);
      i++;
    }
  return (1);
}

void		scan_built(t_tree *tree, t_data *data)
{
  t_node	*node;
  char		**cmd;

  node = tree->root;
  cmd = node->args_l;
  built_launch(cmd, data);
  while (node)
    {
      cmd = node->args_r;
      built_launch(cmd, data);
      node = node->up;
    }
}
