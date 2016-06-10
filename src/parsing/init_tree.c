/*
** init.c for minishell2 in /home/thierry/Rendu/parsems2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Tue May 10 11:08:51 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:07:29 2016 Alexandre BARA
*/

#include	"parsing.h"

void	set_args(char ***args, char **darray, int *i)
{
  int	j;

  j = 0;
  while (darray[*i] && is_token(darray[*i]))
     {
       realloc_darray(args, j + 2);
       (*args)[j] = darray[*i];
       *i += 1;
       j++;
    }
}

void		init_darray(t_tree **tree, char **darray, int *i)
{
  t_node	*tmp;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->root_node = 1;
  tmp->token = 0;
  tmp->up = NULL;
  tmp->args_l = NULL;
  tmp->args_r = NULL;
  (*tree)->root = tmp;
  (*tree)->branch = tmp;
  set_args(&tmp->args_l, darray, i);
  if (darray[*i] && !is_token(darray[*i]))
    {
      tmp->token = ret_token(darray[*i]);
      *i += 1;
      set_args(&tmp->args_r, darray, i);
    }
}

void		add_cmds(t_tree **tree, char **darray, int *i)
{
  t_node	*tmp;

  tmp = my_xmalloc(sizeof(*tmp));
  tmp->root_node = 0;
  tmp->token = 0;
  tmp->up = NULL;
  tmp->args_l = NULL;
  tmp->args_r = NULL;
  tmp->token = ret_token(darray[*i]);
  *i += 1;
  set_args(&tmp->args_r, darray, i);
  (*tree)->branch->up = tmp;
}

void	darray_to_tree(t_tree **tree, char **darray)
{
  int	i;

  i = 0;
  init_darray(tree, darray, &i);
  while (darray[i])
    {
      add_cmds(tree, darray, &i);
      (*tree)->branch = (*tree)->branch->up;
    }
  (*tree)->branch = (*tree)->root;
}
