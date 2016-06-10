/*
** str_to_wordtab.c for minishell2 in /home/thierry/Rendu/epur_str
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri May 13 00:42:25 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:50:00 2016 Hadrien GOUTAS
*/

#include	<stdlib.h>
#include	<stdio.h>
#include	<string.h>
#include	<strings.h>
#include	"parsing.h"
#include	"string_cu.h"

void		skip_space_tab(char *str, int *i)
{
  while (str && *i < my_strlen(str) && str[*i] &&
	 (str[*i] == ' ' || str[*i] == '\t'))
    *i += 1;
}

void		skip_or_add(char *str, int *i)
{
  if (str && (str[*i] == ' ' || str[*i] == '\t'))
    skip_space_tab(str, i);
  else if (str && str[*i])
    *i += 1;
}

int		count_words(char *str)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  skip_space_tab(str, &i);
  while (str[i] != '\0')
    {
      i++;
      if ((str[i - 1] != ' ' || str[i - 1] != '\t') &&
	  (str[i] == ' ' || str[i] == '\t' || str[i] == '\0'))
	{
	  count++;
	  skip_space_tab(str, &i);
	}
    }
  return (count);
}

void		strcatchar(char *str, char c)
{
  int		i;

  i = 0;
  if (str)
    {
      while (str[i] != '\0')
	i++;
      str[i] = c;
      str[i + 1] = '\0';
    }
}

char		**str_to_wordtab(char *str)
{
  char		**tmp;
  int		j;
  int		k;

  tmp = my_xmalloc(sizeof(char *) * (count_words(str) + 1));
  j = 0;
  while (j < count_words(str))
    {
      tmp[j] = my_xmalloc(my_strlen(str) + 1);
      bzero(tmp[j++], my_strlen(str) + 1);
    }
  tmp[j] = NULL;
  j = 0;
  k = 0;
  skip_space_tab(str, &k);
  while (str[k])
    {
      if (str && str[k] != ' ' && str[k] != '\t' &&
	  k < my_strlen(str) && j < count_words(str))
	strcatchar(tmp[j], str[k]);
      else
	j++;
      skip_or_add(str, &k);
    }
  return (tmp);
}
