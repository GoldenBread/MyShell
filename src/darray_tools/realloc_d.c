/*
** realloc.c for minishell2 in /home/thierry/Rendu/ms2/src/darray_tools
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 12 01:57:48 2016 Thierry LEVISSE
** Last update Tue May 31 15:12:28 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	"parsing.h"

void	realloc_darray(char ***str, size_t size)
{
  char		**tmp;
  unsigned int	i;

  i = 0;
  tmp = my_xmalloc(sizeof(*tmp) * size);
  bnull(tmp, size);
  while (*str && (*str)[i] != NULL)
    {
      tmp[i] = (*str)[i];
      i++;
    }
  if (*str)
    free(*str);
  *str = tmp;
}
