/*
** cmd_exec.c for cmd_exec in /home/goutas_h/rendu/PSU_2015_42sh
** 
** Made by Hadrien GOUTAS
** Login   <goutas_h@epitech.net>
** 
** Started on Sun Jun  5 12:46:46 2016 Hadrien GOUTAS
** Last update Sun Jun  5 22:22:42 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	"parse_tree.h"
#include	"string_cu.h"
#include	"shell.h"

void	normal_quit(char **arge, t_data *data)
{
  my_putstr("exit\n");
  free_darray(arge);
  exit(data->exit_value);
}

int	handle_cmd_str(char **cmd_str, char *cmd_str_raw)
{
  int	size;
  int	ret;

  size = 0;
  ret = 0;
  while (cmd_str_raw[size] && !(ret = ret_separator(cmd_str_raw, size)))
    size++;
  *cmd_str = my_xmalloc(size + 1);
  my_bzero(*cmd_str, size + 1);
  my_strcpy_sized(*cmd_str, cmd_str_raw, size);
  if (ret > 1)
    str_put_back(cmd_str_raw, size + 2);
  else
    str_put_back(cmd_str_raw, size + 1);
  return (ret);
}

void	core_exec(t_tree *tree, t_data *data)
{
  int	io[2];

  if (tree && !ambi_redir(tree))
    {
      io[0] = xdup(0);
      io[1] = xdup(1);
      if (io[0] != -1 && io[1] != -1)
	{
	  redir_right(&tree->redir_st);
	  redir_right(&tree->redir_nd);
	  checkiftoken(tree, &data->env);
	  scan_built(tree, data);
	  pipe_it(tree, &data->env);
	  xdup2(io[0], 0);
	  xdup2(io[1], 1);
	}
      close(io[0]);
      close(io[1]);
    }
}

void	var_existing(t_data *data)
{
  if (varexist("PATH=", data->env) == 1)
    put_default_path(data);
}
