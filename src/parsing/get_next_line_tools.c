/*
** get_next_line.c for gnl in /home/thierry/Rendu/get_next_line_ult
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Apr 29 21:54:12 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:04:45 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"

int		check_buf_backn(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\n')
	return (1);
      i++;
    }
  return (0);
}

void		set_in_b_buf(char *buf, char *b_buf, char *get_read)
{
  int		i;
  int		j;
  int		len;

  i = 0;
  len = my_strtool(buf, 0, 0);
  while (get_read[i] != '\n')
    {
      buf[i + len] = get_read[i];
      i++;
    }
  i++;
  j = 0;
  while (get_read[i] != '\0')
    {
      b_buf[j] = get_read[i];
      i++;
      j++;
    }
}

void		my_realloc_spe(char **str, size_t size)
{
  char		*tmp;
  unsigned int	i;

  i = 0;
  tmp = my_xmalloc(size);
  my_strtool(tmp, 1, size);
  while ((*str)[i] != '\0')
    {
      tmp[i] = (*str)[i];
      i++;
    }
  free(*str);
  *str = tmp;
}

void		my_strcat_spe(char *dest, char *src)
{
  int		i;
  int		j;

  i = 0;
  j = my_strtool(dest, 0, 0);
  while (src[i] != 0)
    {
      dest[j + i] = src[i];
      i++;
    }
  dest[j + i] = '\0';
}

int		my_strtool(char *str, int mode, int size)
{
  int		i;

  i = 0;
  if (mode == 1)
    while (i < size)
      {
	str[i] = '\0';
	i++;
      }
  else
    {
      while (str[i] != '\0')
	i++;
    }
  return (i);
}
