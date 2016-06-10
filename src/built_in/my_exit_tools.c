/*
** my_exit_tools.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat Jun  4 19:52:16 2016 Thierry LEVISSE
** Last update Sat Jun  4 20:18:25 2016 Thierry LEVISSE
*/

#include	"string_cu.h"

void	dec_and_sup(char *str)
{
  int	i;

  i = 0;
  while (str[i + 1] != '\0')
    {
      str[i] = str[i + 1];
      i++;
    }
  str[i - 1] = '\0';
}

int	check_parenthesis(char *str)
{
  while (str[0] == '(' && str[my_strlen(str) - 1] == ')')
    dec_and_sup(str);
  if ((str[0] == '(' && str[my_strlen(str)] != ')') ||
      (str[0] != '(' && str[my_strlen(str)] == ')'))
    {
      my_putstr_err("Too many ('s.\n");
      return (1);
    }
  if (str[0] != '(' && str[my_strlen(str)] != ')')
    return (0);
  return (2);
}

int	check_nbr(char *str)
{
  int	i;

  i = 0;
  if (check_parenthesis(str) != 0)
    return (3);
  while (str[i] != '\0')
    {
      if ((str[i] < '0' || str[i] > '9') && (str[0] != '-'))
	{
	  if (str[0] < '0' || str[0] > '9')
	    return (2);
	  else
	    return (1);
	}
      if (str[i] == '-' && i != 0)
	return (1);
    i++;
    }
  return (0);
}

int		my_getnbr(char *str)
{
  int		i;
  int		nb;

  nb = 0;
  i = 0;
  while ((str[i] != '\0' && str[i] < 48) || (str[i] > 57 && str[i] != '\0'))
    i++;
  while (str[i] >= 48 && str[i] <= 57)
    {
      nb = nb * 10;
      nb = nb + (str[i] - 48);
      i++;
    }
  return (nb);
}
