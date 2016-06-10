/*
** epur_quote.c for 42sh in /home/kania_r/rendu/PSU/PSU_2015_42sh/src/echo
** 
** Made by Romain KANIA
** Login   <kania_r@epitech.net>
** 
** Started on Thu Jun  2 18:31:07 2016 Romain KANIA
** Last update Sun Jun  5 03:14:40 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<string.h>
#include	"parsing.h"

int		changestatue(int *n, int statue, char *c, char *strcpy)
{
  if (*c == '\"' && statue == 0)
    {
      if (strcpy[*n - 1] != ' ')
	{
	  strcpy[*n] = ' ';
	  (*n)++;
	}
      statue = 1;
    }
  else if (*c == '\"' && statue == 1)
    statue = 0;
  return (statue);
}

int		new_check(int check, int *n, char *strcpy)
{
  strcpy[*n] = ' ';
  if (check == 0)
    {
      (*n)++;
      check = 1;
    }
  return (check);
}

char		*epur_quote(char *str)
{
  int		n;
  int		i;
  int		statue;
  char		*strcpy;
  int		check;

  n = 0;
  strcpy = my_xmalloc(sizeof(char) * (strlen(str) + 1));
  statue = 0;
  i = 0;
  while (str[i])
    {
      check = 0;
      while (str[i] == ' ' && statue == 0 && str[i])
	{
	  check = new_check(check, &n, strcpy);
	  i++;
	}
      statue = changestatue(&n, statue, &str[i], strcpy);
      strcpy[n++] = str[i++];
    }
  strcpy[n] = '\0';
  free(str);
  return (strcpy);
}
