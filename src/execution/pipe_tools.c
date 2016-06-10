/*
** pipe_tools.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jun  5 21:36:51 2016 Thierry LEVISSE
** Last update Sun Jun  5 21:36:51 2016 Thierry LEVISSE
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"shell.h"
#include	"parse_tree.h"

int		get_nbr_piped_args(t_tree *tree)
{
  t_node	*tmp;
  int		i;

  i = 0;
  tmp = tree->root;
  while (tmp)
    {
      if (tmp->token == 5)
	i++;
      tmp = tmp->up;
    }
  if (i > 0)
    i++;
  return (i);
}

void		close_pipes(int *pipefd, int nbr_pipes)
{
  int		i;

  i = 0;
  while (i < (nbr_pipes - 1) * 2)
    {
      close(pipefd[i]);
      i++;
    }
}

int		prep_pipefd(int *pipefd, int nbr_pipes)
{
  int		i;

  i = 0;
  while (i < (nbr_pipes) - 1)
    {
      if (pipe(pipefd + i * 2) == -1)
	{
	  fprintf(stderr, "Can't make pipe.\n");
	  return (1);
	}
      i++;
    }
  return (0);
}

char		**get_cmd(t_tree *tree, int nbr_cmd)
{
  int		cnt;

  cnt = 0;
  if (nbr_cmd > 1 && cnt < nbr_cmd - 1)
    tree->branch = tree->branch->up;
  if (nbr_cmd == 0)
    return (tree->branch->args_l);
  else
    return (tree->branch->args_r);
}
