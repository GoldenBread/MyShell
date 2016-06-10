/*
** check_token.c for minishell2 in /home/thierry/Rendu/parsems2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Wed May 11 01:13:35 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:02:28 2016 Thierry LEVISSE
*/

#include	<stdio.h>
#include	"parsing.h"
#include	"string_cu.h"

int	true_token(char *str)
{
  if (((str[0] == '<' || str[0] == '>') &&
       my_strlen(str) > 2 && str[1] != '\0' &&
       str[1] != '<' && str[1] != '>') ||
      (str[0] == '|' && str[1] != '\0'))
    return (1);
  return (0);
}

int	check_token(char **darray)
{
  int	i;

  i = 0;
  while (darray[i])
    {
      if ((darray[i][0] == '>' ||
	   darray[i][0] == '<' ||
	   darray[i][0] == '|') || !true_token(darray[i]))
	return (1);
      i++;
    }
  return (0);
}

int	is_token(char *str)
{
  if (((str[0] == '>' ||
	str[0] == '<' ||
	str[0] == '|') && true_token(str)) ||
      (str[0] != '>' &&
       str[0] != '<' &&
       str[0] != '|'))
    return (1);
  return (0);
}

int	ret_token(char *str)
{
  char	token[5][3];
  int	i;

  my_strcpy(token[0], ">");
  my_strcpy(token[1], "<");
  my_strcpy(token[2], ">>");
  my_strcpy(token[3], "<<");
  my_strcpy(token[4], "|");
  i = 0;
  while (i < 5)
    {
      if (!my_strcmp(token[i], str))
	return (i + 1);
      i++;
    }
  return (0);
}
