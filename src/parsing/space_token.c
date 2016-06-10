/*
** space_token.c for minishell2 in /home/thierry/Rendu/parsems2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Tue May 10 15:12:23 2016 Thierry LEVISSE
** Last update Thu Jun  2 14:29:01 2016 Thierry LEVISSE
*/

#include	"parsing.h"
#include	"string_cu.h"

void	space_delayed(char *str, int i)
{
  int	to_i;

  to_i = my_strlen(str);
  while (to_i > i)
    {
      str[to_i] = str[to_i - 1];
      to_i--;
    }
  str[i] = ' ';
}

void	space_token(char **str)
{
  int	i;

  i = 1;
  while (i < my_strlen(*str))
    {
      if (((*str)[i] == '>' && (*str)[i - 1] != '>') ||
	  ((*str)[i] == '<' && (*str)[i - 1] != '<') ||
	  ((*str)[i - 1] == '>' && (*str)[i] != '>') ||
	  ((*str)[i - 1] == '<' && (*str)[i] != '<') ||
	  ((*str)[i] == '|' && (*str)[i - 1] != ' ') ||
	  ((*str)[i - 1] == '|' && (*str)[i] != ' '))
	{
	  my_realloc(str, my_strlen(*str) + 2);
	  space_delayed(*str, i);
	  i++;
	}
      i++;
    }
}
