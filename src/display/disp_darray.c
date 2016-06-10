/*
** disp_darray.c for minishell2 in /home/thierry/Rendu/ms2/src/display
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu May 12 01:54:32 2016 Thierry LEVISSE
** Last update Sun Jun  5 02:47:39 2016 Thierry LEVISSE
*/

#include	<stdio.h>
#include	"string_cu.h"

void	disp_darray(char **darray)
{
  int	i;

  i = 0;
  while (darray && darray[i])
    {
      printf("%s\n", darray[i]);
      i++;
    }
}
