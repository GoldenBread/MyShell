/*
** ambi_redir.c for 42sh in /tmp/PSU_2015_42sh/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat Jun  4 02:23:24 2016 Thierry LEVISSE
** Last update Sat Jun  4 13:36:28 2016 Thierry LEVISSE
*/

#include	"parse_tree.h"
#include	"parsing.h"

int	ambiredir(char **wordtab)
{
  int	ret;

  ret = 0;
  ret += nbr_redir(wordtab, ret);
  ret += check_name(wordtab, ret);
  ret += check_alone(wordtab, ret);
  ret += check_encounter(wordtab, ret);
  if (ret > 0)
    return (1);
  return (0);
}
