/*
** disp_tree_cmd.c for minishell2 in /home/thierry/Rendu/ms2/src/display
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 12 01:55:23 2016 Thierry LEVISSE
** Last update Sun Jun  5 02:48:42 2016 Thierry LEVISSE
*/

#include	<stdio.h>
#include	"parse_tree.h"
#include	"string_cu.h"

void		disp_tree_cmd(t_tree *tree)
{
  t_node	*node;

  node = tree->root;
  while (node)
    {
      printf("root\n");
      my_putstr("args_l: ");
      disp_darray(node->args_l);
      my_putstr("token: ");
      printf("%d\n", node->token);
      my_putstr("args_r: ");
      disp_darray(node->args_r);
      node = node->up;
    }
}
