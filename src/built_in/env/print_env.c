/*
** print_env.c for print_env in /home/wanty_w/rendu/PSU_2015_42sh/env
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Tue May 31 15:48:55 2016 William WANTY
** Last update Sat Jun  4 18:46:38 2016 Thierry LEVISSE
*/

#include	<stdio.h>
#include	<string.h>
#include	"shell.h"
#include	"parse_tree.h"

void	print_env(char **env)
{
  int	i;

  i = 0;
  while (env[i] != NULL)
    {
      fprintf(stderr, "%s\n", env[i]);
      i++;
    }
}
