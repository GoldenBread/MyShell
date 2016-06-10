/*
** get_next_line.c for gnl in /home/thierry/Rendu/get_next_line_ult
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Apr 29 21:54:12 2016 Thierry LEVISSE
** Last update Thu Jun  2 14:29:20 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"parsing.h"
#include	"string_cu.h"

void		my_realloc(char **str, size_t size)
{
  char		*tmp;
  unsigned int	i;

  i = 0;
  tmp = my_xmalloc(size);
  my_bzero(tmp, size);
  while ((*str)[i] != '\0')
    {
      tmp[i] = (*str)[i];
      i++;
    }
  free(*str);
  *str = tmp;
}
