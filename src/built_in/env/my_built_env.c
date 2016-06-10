/*
** my_built_env.c for built_env in /home/wanty_w/rendu/PSU_2015_minishell2
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Fri Apr  1 16:01:42 2016 William WANTY
** Last update Sun Jun  5 03:03:43 2016 Thierry LEVISSE
*/

#include	<unistd.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<sys/types.h>
#include	<sys/wait.h>
#include	"parse_tree.h"
#include	"parsing.h"
#include	"shell.h"

void	replace_env(char ***env, int i)
{
  while ((*env)[i + 1] != NULL)
    {
      (*env)[i] = my_xmalloc(sizeof(char) * strlen((*env)[i + 1]) + 1);
      bzero((*env)[i], strlen((*env)[i + 1]) + 1);
      strcpy((*env)[i], (*env)[i + 1]);
      i++;
    }
  (*env)[i] = NULL;
}

void	my_set_null(char *env)
{
  int	i;

  i = 0;
  while (env[i] != '=' && env[i] != '\0')
    i++;
  if (env[i] == '=')
    {
      i++;
      while (env[i] != '\0')
	{
	  env[i] = '\0';
	  i++;
	}
    }
}

void	set_new(char **cmd_tab, int i, char **env)
{
  int	j;
  int	n;

  j = 0;
  n = 0;
  while (cmd_tab[1][n] != '\0')
    {
      env[i][n] = cmd_tab[1][n];
      n++;
    }
  env[i][n++] = '=';
  env[i][n] = '\0';
  if (cmd_tab[2] != NULL)
    {
      while (cmd_tab[2][j] != '\0')
	env[i][n++] = cmd_tab[2][j++];
      env[i][n] = '\0';
      i++;
    }
}

void	new_var_env(char **cmd_tab, char ***env)
{
  int	i;

  i = 0;
  realloc_darray(env, darray_len(*env) + 2);
  while ((*env)[i] != NULL)
    i++;
  if (cmd_tab[2] == NULL)
    (*env)[i] = my_xmalloc(strlen(cmd_tab[1]) + 2);
  else
    (*env)[i] = my_xmalloc(strlen(cmd_tab[1]) + strlen(cmd_tab[2]) + 2);
  set_new(cmd_tab, i, *env);
}

void	my_setenv(char **command, t_data *data)
{
  if (command[1] == NULL)
    print_env(data->env);
  else if (check_char_setenv(command) == 0)
    {
      if (modif_env(command, &data->env) != 1)
	new_var_env(command, &data->env);
    }
}
