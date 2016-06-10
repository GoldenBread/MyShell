/*
** str_cpy.c for str_cpy in /home/wanty_w/rendu/Minishell2/src/libmy
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Thu Apr 21 17:06:43 2016 William WANTY
** Last update Thu May 19 17:11:40 2016 William WANTY
*/

#include <unistd.h>
#include "lib.h"

void	my_str_cpy(char *src, char *dest)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}
