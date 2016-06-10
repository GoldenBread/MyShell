/*
** get_next_line.c for gnl in /home/thierry/Rendu/get_next_line_ult
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Apr 29 21:54:12 2016 Thierry LEVISSE
** Last update Thu Jun  2 11:22:41 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	"get_next_line.h"

char	*get_next_line_loop(const int fd,
			    char *buf,
			    char *b_buf,
			    int *stop_read_gb)
{
  char	get_read[READ_SIZE + 1];
  int	stop_read;
  int	ret_read;

  stop_read = 0;
  while (stop_read != 1)
    {
      my_strtool(get_read, 1, READ_SIZE + 1);
      ret_read = read(fd, get_read, READ_SIZE);
      if (ret_read > 0 && check_buf_backn(get_read) == 0)
	{
	  my_realloc_spe(&buf, my_strtool(buf, 0, 0) + (READ_SIZE + 1) * 2);
	  my_strcat_spe(buf, get_read);
	}
      else
	{
	  if (check_buf_backn(get_read) == 1)
	    set_in_b_buf(buf, b_buf, get_read);
	  stop_read = 1;
	}
    }
  if (ret_read == 0)
    *stop_read_gb = 1;
  return (buf);
}

void	decalate_b_buf(char *b_buf)
{
  int	diff;
  int	i;
  int	len;

  len = my_strtool(b_buf, 0, 0);
  diff = 0;
  while (b_buf[diff] != '\n' && b_buf[diff] != '\0')
    diff++;
  diff++;
  i = 0;
  while (b_buf[i] != '\0')
    {
      if (i + diff < len)
	b_buf[i] = b_buf[i + diff];
      else
	b_buf[i] = 0;
      i++;
    }
}

int	b_buf_loop(char *b_buf, char *buf)
{
  int	i;
  int	ret;

  i = 0;
  ret = 0;
  if (b_buf[0] != '\0')
    {
      while (b_buf[i] != '\n' && b_buf[i] != '\0')
	{
	  buf[i] = b_buf[i];
	  i++;
	}
      if (b_buf[i] == '\n' && b_buf[i + 1] == '\0')
	ret = 1;
      decalate_b_buf(b_buf);
      if (b_buf[0] != '\0' || ret == 1)
      	return (1);
    }
  return (0);
}

void	purge_b_buff_loop(char *b_buf)
{
  if (b_buf[my_strtool(b_buf, 0, 0) - 1] == '\n')
    b_buf[my_strtool(b_buf, 0, 0) - 1] = '\0';
}

char		*get_next_line(const int fd, int reinit)
{
  char		*buf;
  static int	stop_read = 0;
  static char	b_buf[READ_SIZE + 1];

  if (reinit == 1)
    {
      stop_read = 0;
      return (NULL);
    }
  if (b_buf[0] == 0 && stop_read == 1)
    return (NULL);
  buf = my_xmalloc((READ_SIZE + 1) * 2);
  my_strtool(buf, 1, (READ_SIZE + 1) * 2);
  if (b_buf_loop(b_buf, buf) == 0)
    buf = get_next_line_loop(fd, buf, b_buf, &stop_read);
  if (buf[0] == 0 && b_buf[0] == 0 && stop_read == 1)
    {
      free(buf);
      return (NULL);
    }
  return (buf);
}
