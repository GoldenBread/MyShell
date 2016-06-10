/*
** check_redir.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat Jun  4 13:40:17 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:07:04 2016 Alexandre BARA
*/

#include	<stdio.h>
#include	"parse_tree.h"
#include	"parsing.h"

int	nbr_redir(char **wordtab, int err)
{
  int	i;
  int	cnt;
  int	ret;

  i = 0;
  cnt = 0;
  while (wordtab[i] && !err)
    {
      ret = ret_token(wordtab[i]);
      if (ret > 0 && ret < 5)
	cnt++;
      i++;
    }
  if (cnt > 2)
    {
      fprintf(stderr, "Ambiguous output redirect.\n");
      return (1);
    }
  return (0);
}

int	check_name(char **wordtab, int err)
{
  int	i;
  int	ret;

  i = 0;
  while (wordtab[i] && !err)
    {
      ret = ret_token(wordtab[i]);
      if (ret > 0 && ret < 5 &&
	  (!wordtab[i + 1] || ret_token(wordtab[i + 1]) > 0))
	{
	  fprintf(stderr, "Missing name for redirect.\n");
	  return (1);
	}
      i++;
    }
  return (0);
}

int	check_alone(char **wordtab, int err)
{
  int	i;
  int	ret;
  int	valid_case;

  valid_case = 0;
  i = 0;
  while (wordtab[i] && ret_token(wordtab[i]) != 5 && !err)
    {
      ret = ret_token(wordtab[i]);
      if (i == 0 &&
	  ret > 0 && ret < 5 &&
	  wordtab[i + 1] && ret_token(wordtab[i + 1]) == 0)
	valid_case = 1;
      i++;
    }
  if (i == 2 && valid_case == 1)
    {
      fprintf(stderr, "Invalid null command.\n");
      return (1);
    }
  return (0);
}

int	forward_backward(char **wordtab, int i, int mode)
{
  while (mode == 0 && wordtab[i])
    {
      if (ret_token(wordtab[i]) == 5)
	return (1);
      i++;
    }
  while (mode == 1 && i >= 0)
    {
      if (ret_token(wordtab[i]) == 5)
	return (1);
      i--;
    }
  return (0);
}

int	check_encounter(char **wordtab, int err)
{
  int	i;
  int	ret;
  int	cnt;

  i = 0;
  cnt = 0;
  while (wordtab[i] && !err)
    {
      ret = ret_token(wordtab[i]);
      if (ret == 1 || ret == 3)
	cnt += forward_backward(wordtab, i, 0);
      else if (ret == 2 || ret == 4)
	cnt += forward_backward(wordtab, i, 1);
      i++;
    }
  if (cnt > 0)
    {
      fprintf(stderr, "Ambiguous output redirect.\n");
      return (1);
    }
  return (0);
}
