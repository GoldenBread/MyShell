/*
** get_redir.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun  3 16:19:30 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:05:23 2016 Alexandre BARA
*/

#include	<string.h>
#include	"parsing.h"
#include	"parse_tree.h"

void	get_redir(char **wordtab, t_tree *tree)
{
  int	i;
  int	ret;

  tree->redir_st.name = NULL;
  tree->redir_nd.name = NULL;
  i = 0;
  while (wordtab[i])
    {
      ret = ret_token(wordtab[i]);
      if (ret == 1 || ret == 2 || ret == 3 || ret == 4)
	{
	  if (tree->redir_st.name == NULL)
	    {
	      tree->redir_st.name = wordtab[i + 1];
	      tree->redir_st.token = ret;
	    }
	  else if (tree->redir_nd.name == NULL)
	    {
	      tree->redir_nd.name = wordtab[i + 1];
	      tree->redir_nd.token = ret;
	    }
	}
      i++;
    }
}
