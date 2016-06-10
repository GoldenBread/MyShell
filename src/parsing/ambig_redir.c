/*
** ambig_redir.c for ambiguous in /home/goutas_h/rendu/PSU_2015_42sh
** 
** Made by Hadrien GOUTAS
** Login   <goutas_h@epitech.net>
** 
** Started on Thu Jun  2 15:13:28 2016 Hadrien GOUTAS
** Last update Fri Jun  3 17:16:22 2016 Hadrien GOUTAS
*/

#include	<unistd.h>
#include	<stdio.h>
#include	"parse_tree.h"

int		look_first_and_last(t_node *node)
{
  int		cnt;

  cnt = 0;
  while (node)
    {
      if (cnt++ == 0)
	{
	  if (node->token != 0 && (node->args_l == NULL || node->args_r == NULL))
	    {
	      fprintf(stderr, "Invalid null command.\n");
	      return (1);
	    }
	}
      else
	{
	  if (node->token != 0 && node->args_r == NULL)
	    {
	      fprintf(stderr, "Invalid null command.\n");
	      return (1);
	    }
	}
      node = node->up;
    }
  return (0);
}

int		ambi_redir_left(t_node *node)
{
  int		cnt;

  cnt = 0;
  if (look_first_and_last(node) == 1)
    return (1);
  while (node)
    {
      if (node->token != 5 && cnt != 0)
	{
	  fprintf(stderr, "Ambiguous input redirect.\n");
	  return (1);
	}
      if (node->token == 4 || node->token == 2)
	cnt++;
      node = node->up;
    }
  return (0);
}

int		ambi_redir_right(t_node *node)
{
  int		cnt;

  cnt = 0;
  while (node)
    {
      if (node->token != 5 && cnt != 0)
	{
	  fprintf(stderr, "Ambiguous output redirect.\n");
	  return (1);
	}
      if (node->token == 1 || node->token == 3)
	cnt++;
      node = node->up;
    }
  return (0);
}

int		ambi_redir(t_tree *tree)
{
  if (ambi_redir_left(tree->root) == 1)
    return (1);
  if (ambi_redir_right(tree->root) == 1)
    return (1);
  return (0);
}
