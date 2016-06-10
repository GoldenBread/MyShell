/*
** my_quote_to_wordtab.c for 42sh in /home/kania_r/rendu/PSU/42
** 
** Made by Romain KANIA
** Login   <kania_r@epitech.net>
** 
** Started on Thu Jun  2 12:47:20 2016 Romain KANIA
** Last update Sun Jun  5 03:14:06 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	"parsing.h"

int		countwords(char *str)
{
  int		nb;
  int		i;
  int		statue;

  statue = 0;
  i = 0;
  nb = 1;
  while (str[i])
    {
      if (str[i] == ' ' && statue == 0)
	nb++;
      if (str[i] == '\"' && statue == 0)
	statue = 1;
      else if (str[i] == '\"' && statue == 1)
	{
	  nb++;
	  statue = 0;
	}
      i++;
    }
  return (nb);
}

int		statueforwordtab(char *str, int i, int statue)
{
  if (str[i] == '\"' && statue == 0)
    statue = 1;
  else if (str[i] == '\"' && statue == 1)
    statue = 0;
  return (statue);
}

char		**mallocmytab(int len, char *str)
{
  int		x;
  int		nb;
  char		**tab;

  nb = countwords(str);
  x = 0;
  tab = my_xmalloc(sizeof(char *) * (nb + 1));
  while (x < nb)
    tab[x++] = my_xmalloc(sizeof(char) * (len + 1));
  return (tab);
}

char		**my_quote_to_wordtab(char *str)
{
  char		**tab;
  int		x;
  int		y;
  int		statue;
  int		i;

  i = 0;
  statue = 0;
  y = 0;
  tab = mallocmytab(strlen(str), str);
  while (str[i])
    {
      x = 0;
      while ((str[i] != ' ' || statue == 1) && str[i])
	{
	  statue = statueforwordtab(str, i, statue);
	  tab[y][x++] = str[i++];
	}
      tab[y++][x] = '\0';
      if (str[i] != '\0')
	i++;
    }
  tab[y] = NULL;
  return (tab);
}
