/*
** signal.c for 42sh in /home/kania_r/rendu/PSU/42
** 
** Made by Romain KANIA
** Login   <kania_r@epitech.net>
** 
** Started on Mon May 30 13:20:09 2016 Romain KANIA
** Last update Sat Jun  4 17:52:39 2016 Thierry LEVISSE
*/

#include	<stdio.h>
#include	<sys/types.h>
#include	<sys/wait.h>

void		printsig(int sig)
{
  if (WIFEXITED(sig) != 1)
    {
      if (WTERMSIG(sig) == 11)
        fprintf(stderr, "Segmentation fault (core dumped)\n");
      if (WTERMSIG(sig) == 6)
        fprintf(stderr, "Abort (core dumped)\n");
      if (WTERMSIG(sig) == 8)
        fprintf(stderr, "Floating exception (core dumped)\n");
    }
}
