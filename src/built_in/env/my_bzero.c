/*
** my_bzero.c for bzero in /home/wanty_w/rendu/PSU_2015_minishell2/src/libmy
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Fri Apr  1 16:22:50 2016 William WANTY
** Last update Wed May  4 16:23:43 2016 William WANTY
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "mysh.h"
#include "lib.h"

void	tab_bzero(char **tab, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      tab[i] = NULL;
      i++;
    }
}

void	my_bzero(char *buf, int size)
{
  int	i;

  i = 0;
  while (i < size)
    {
      buf[i] = '\0';
      i++;
    }
}

void	my_bzero_n(char *str, int size, int n)
{
  while (n < size)
    {
      str[n] = '\0';
      n++;
    }
}
