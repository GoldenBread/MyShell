/*
** free_tree.c for minishell2 in /home/thierry/Rendu/ms2/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 12 02:01:00 2016 Thierry LEVISSE
** Last update Tue May 31 02:48:43 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	"parsing.h"
#include	"parse_tree.h"

void		free_tree(t_tree *tree)
{
  t_node	*tmp;
  t_node	*free_node;

  tmp = tree->root;
  while (tmp)
    {
      if (tmp->args_l)
	free_darray(tmp->args_l);
      if (tmp->args_r)
	free_darray(tmp->args_r);
      free_node = tmp;
      tmp = tmp->up;
      if (free_node)
	free(free_node);
    }
}
