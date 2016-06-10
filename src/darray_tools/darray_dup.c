/*
** darray_dup.c for minishell2 in /home/thierry/Rendu/ms2/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 12 02:12:32 2016 Thierry LEVISSE
** Last update Thu Jun  2 14:26:24 2016 Thierry LEVISSE
*/

#include	"parsing.h"
#include	"string_cu.h"

char		**d_array_dup(char **d_array)
{
  char		**tmp;
  int		i;

  i = 0;
  while (d_array[i] != NULL)
    i++;
  tmp = my_xmalloc(sizeof(char *) * (i + 1));
  i = 0;
  while (d_array[i] != NULL)
    {
      tmp[i] = my_strdup(d_array[i]);
      i++;
    }
  tmp[i] = NULL;
  return (tmp);
}
