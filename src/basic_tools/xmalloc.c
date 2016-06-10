/*
** xmalloc.c for minishell2 in /home/thierry/Rendu/PSU_2015_minishell2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Mon Apr 25 13:24:54 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:35:54 2016 Hadrien GOUTAS
*/

#include	<stdlib.h>
#include	<string.h>
#include	"parsing.h"

void	*my_xmalloc(size_t size)
{
  void	*tmp;

  if (!(tmp = malloc(size + 1)))
    exit_errors(2);
  bzero(tmp, size);
  return (tmp);
}
