/*
** strdup.c for 42sh in /home/thierry/Github/MyShell/src/string
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun 10 02:24:26 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:24:27 2016 Thierry LEVISSE
*/

#include	"parsing.h"
#include	"string_cu.h"

char	*my_strdup(char *src)
{
  char	*dest;

  if (!(dest = my_xmalloc(my_strlen(src) + 2)))
    exit_errors(2);
  my_strcpy(dest, src);
  return (dest);
}

char	*my_strdup_plus(char *src, int plus)
{
  char	*dest;

  if (!(dest = my_xmalloc(my_strlen(src) + 1 + plus)))
    exit_errors(2);
  my_strcpy(dest, src);
  return (dest);
}

char	*my_strdup_plus_sized(char *src, int length)
{
  char	*dest;

  if (!(dest = my_xmalloc(length + 1)))
    exit_errors(2);
  my_strcpy_sized(dest, src, length);
  return (dest);
}
