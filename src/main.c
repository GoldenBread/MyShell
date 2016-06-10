/*
** main.c for main in /home/wanty_w/rendu/PSU_2015_42sh/src
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Mon May 30 10:41:54 2016 William WANTY
** Last update Sun Jun  5 21:49:59 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<signal.h>
#include	<stdio.h>
#include	"get_next_line.h"
#include	"parse_tree.h"
#include	"string_cu.h"
#include	"shell.h"

void		signal_control(int signo)
{
  extern char	**environ;
  char		*prompt;

  prompt = get_prompt(environ);
  if (signo == SIGINT && isatty(1) == 1)
    {
      my_putstr("\n");
      my_putstr(prompt);
    }
  else if (signo == SIGQUIT)
    exit(0);
  free(prompt);
}

void	str_put_back(char *str, int n)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      str[i] = str[n];
      i++;
      if (str[n])
	n++;
    }
}

void	coreloop(char *cmd_str_raw, t_tree *tree, t_data *data, char old_sep)
{
  char	*cmd_str;

  cmd_str = NULL;
  while (cmd_str_raw && my_strlen(cmd_str_raw))
    {
      var_existing(data);
      data->sep = handle_cmd_str(&cmd_str, cmd_str_raw);
      echo_loop(data, cmd_str);
      if (!ret_value_sep(old_sep, &tree->sucess))
	{
	  tree->sucess = 0;
	  if (!set_tree(&tree, &cmd_str))
	    core_exec(tree, data);
	  if (tree)
	    free_tree(tree);
	}
      old_sep = data->sep;
      if (data->exit_value != 1)
	data->exit_value = tree->sucess;
      free_misc(cmd_str, data);
    }
  free(cmd_str_raw);
}

void		mainloop(t_data *data)
{
  t_tree	tree;
  char		*cmd_str_raw;
  char		*prompt;

  prompt = get_prompt(data->env);
  while (1)
    {
      if (isatty(0) == 1)
	my_putstr(prompt);
      cmd_str_raw = get_next_line(0, 0);
      if (!cmd_str_raw)
	normal_quit(data->env, data);
      tree.sucess = 0;
      data->exit_value = 0;
      coreloop(cmd_str_raw, &tree, data, 0);
    }
  free(prompt);
}

int		main(int argc, char **argv, char **arge)
{
  t_data	data;

  argc = argc;
  argv = argv;
  init_oldpwd(&data);
  init_tabptr(&data);
  init_echo(&data);
  signal(SIGINT, signal_control);
  signal(SIGQUIT, signal_control);
  data.env = d_array_dup(arge);
  data.exit_value = 0;
  mainloop(&data);
}
