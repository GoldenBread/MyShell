/*
** set_tree.c for minishell2 in /home/thierry/Rendu/ms2/src/parsing
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 12 11:45:26 2016 Thierry LEVISSE
** Last update Sun Jun  5 04:14:41 2016 Thierry LEVISSE
*/

#include	<stdio.h>
#include	"shell.h"
#include	"parsing.h"
#include	"parse_tree.h"

int	set_tree(t_tree **tree, char **cmd_str)
{
  char	**darray;

  (*tree)->root = NULL;
  space_token(cmd_str);
  darray = str_to_wordtab(*cmd_str);
  if (ambiredir(darray) == 1)
    return (1);
  get_redir(darray, *tree);
  clean_redir(darray);
  if (!check_token(darray))
    fprintf(stderr, "Uncorrect token\n");
  darray_to_tree(tree, darray);
  if (darray)
    free(darray);
  return (0);
}
