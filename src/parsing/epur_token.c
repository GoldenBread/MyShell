/*
** epur_token.c for minishell2 in /home/thierry/Rendu/parsems2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Tue May 10 13:47:51 2016 Thierry LEVISSE
** Last update Sun Jun  5 02:42:42 2016 Thierry LEVISSE
*/

#include	<stdlib.h>

void		bnull(char **darray, size_t size)
{
  unsigned int	i;

  i = 0;
  while (i < size)
    {
      darray[i] = NULL;
      i++;
    }
}

int	darray_len(char **darray)
{
  int	i;

  i = 0;
  while (darray[i])
    i++;
  return (i);
}
