/*
** modif_env.c for modif_env in /home/wanty_w/rendu/Minishell2/src
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Fri Apr 29 16:19:25 2016 William WANTY
** Last update Fri Jun 10 02:09:33 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	"parse_tree.h"
#include	"parsing.h"
#include	"shell.h"

void	prepare_line(char ***env, char **cmd_tab, int i)
{
  int	tmp;
  int	y;

  y = 0;
  tmp = 0;
  if ((*env)[i])
    free((*env)[i]);
  (*env)[i] = my_xmalloc(strlen(cmd_tab[1]) + strlen(cmd_tab[2]) + 2);
  bzero((*env)[i], strlen(cmd_tab[1]) + strlen(cmd_tab[2]) + 2);
  strcpy((*env)[i], cmd_tab[1]);
  tmp = strlen(cmd_tab[1]);
  (*env)[i][tmp++] = '=';
  while (cmd_tab[2][y] != '\0')
    (*env)[i][tmp++] = cmd_tab[2][y++];
  (*env)[i][tmp] = '\0';
}

int	modif_env(char **cmd_tab, char ***env)
{
  int	i;

  i = 0;
  while ((*env)[i] != NULL)
    {
      if ((my_strcmp_varenv((*env)[i], cmd_tab[1])) == 0)
        {
	  if (cmd_tab[2] == NULL)
	    my_set_null((*env)[i]);
	  else
	    prepare_line(env, cmd_tab, i);
	  return (1);
	}
      i++;
    }
  return (-1);
}
