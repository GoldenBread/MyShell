/*
** darray_malloc.c for minishell2 in /home/thierry/Rendu/epur_str
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 13 00:46:03 2016 Thierry LEVISSE
** Last update Tue May 31 02:44:51 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	"parsing.h"

void		**darray_malloc(size_t x, size_t y, size_t type)
{
  void		**tmp;
  unsigned int	i;

  tmp = my_xmalloc(y * 8);
  i = 0;
  while (i < y - 1)
    {
      tmp[i] = my_xmalloc(x * type);
      my_bzero(tmp[i], x);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}
