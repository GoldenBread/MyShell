/*
** sweep_out.c for 42sh in /home/thierry/Rendu/42_wordtab
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun  3 22:20:31 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:05:48 2016 Alexandre BARA
*/

#include	<stdlib.h>
#include	<string.h>
#include	"parsing.h"
#include	"shell.h"

void	sweep_out(char **wordtab, int pos)
{
  int	len;

  len = darray_len(wordtab);
  while (pos + 2 < len)
    {
      wordtab[pos] = wordtab[pos + 2];
      pos++;
    }
  wordtab[pos] = NULL;
  wordtab[pos + 1] = NULL;
}

void	clean_redir(char **wordtab)
{
  int	i;
  int	break_loop;
  int	ret;

  i = 0;
  while (wordtab[i])
    {
      i = 0;
      break_loop = 0;
      while (wordtab[i] && break_loop == 0)
	{
	  ret = ret_token(wordtab[i]);
	  if (ret > 0 && ret < 5)
	    {
	      break_loop = 1;
	      sweep_out(wordtab, i);
	    }
	  i++;
	}
    }
}
