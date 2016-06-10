/*
** free_darray.c for minishell2 in /home/thierry/Rendu/ms2/src/darray_tools
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 12 02:19:24 2016 Thierry LEVISSE
** Last update Sun Jun  5 02:48:05 2016 Thierry LEVISSE
*/

#include	<stdlib.h>

void	free_darray(char **darray)
{
  int	i;

  i = 0;
  while (darray[i])
    {
      free(darray[i]);
      i++;
    }
  if (darray)
    free(darray);
}
