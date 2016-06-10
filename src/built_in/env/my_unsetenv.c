/*
** my_unsetenv.c for unsetenv in /home/wanty_w/rendu/Minishell2/src
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Fri Apr 29 16:23:23 2016 William WANTY
** Last update Sun Jun  5 03:04:11 2016 Thierry LEVISSE
*/

#include <unistd.h>
#include "shell.h"

int	set_cmp(char *s1, char *s2)
{
  int   i;

  i = 0;
  while (s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  if (s2[i] == '=')
    return (0);
  else
    return (-1);
}

void	my_unsetenv2(char *cmd, char ***env)
{
  int	i;

  i = 0;
  while ((*env)[i] != NULL)
    {
      if (set_cmp(cmd, (*env)[i]) == 0)
        {
	  replace_env(env, i);
	  return ;
	}
      i++;
    }
}

void	my_unsetenv(char **cmd_tab, t_data *data)
{
  int	i;

  i = 1;
  if (cmd_tab[1] == NULL)
    write(2, "unsetenv: Too few arguments.\n", 30);
  else
    {
      while (cmd_tab[i] != NULL)
	{
	  my_unsetenv2(cmd_tab[i], &data->env);
	  i++;
	}
    }
}
