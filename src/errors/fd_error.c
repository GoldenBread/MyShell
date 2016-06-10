/*
** fd_error.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat Jun  4 19:32:12 2016 Thierry LEVISSE
** Last update Sat Jun  4 20:14:19 2016 Thierry LEVISSE
*/

#include	<unistd.h>
#include	<stdio.h>

int	xdup(int fildes)
{
  int	ret;

  if ((ret = dup(fildes)) == -1)
    fprintf(stderr, "Error: cannot duplicate filedescriptor\n");
  return (ret);
}

int	xdup2(int fildes, int fildes2)
{
  int	ret;

  if ((ret = dup2(fildes, fildes2)) == -1)
    fprintf(stderr, "Error: cannot duplicate filedescriptor\n");
  return (ret);
}
