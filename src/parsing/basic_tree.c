/*
** basic_tree.c for minishell2 in /home/thierry/Rendu/parsems2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Wed May 11 14:59:24 2016 Thierry LEVISSE
** Last update Tue May 31 02:47:07 2016 Thierry LEVISSE
*/

#include	"parsing.h"

void	tree_go_root(t_tree *tree)
{
  tree->branch = tree->root;
}
