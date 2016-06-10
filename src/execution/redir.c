/*
** redir.c for 42sh in /home/alexandre/PSU/PSU_2015_42sh
** 
** Made by Alexandre BARA
** Login   <alexandre@epitech.net>
** 
** Started on Mon May 30 12:53:10 2016 Alexandre BARA
** Last update Sun Jun  5 20:23:44 2016 Thierry LEVISSE
*/

#include	<sys/stat.h>
#include	<sys/types.h>
#include	<fcntl.h>
#include	<unistd.h>
#include	<stdlib.h>
#include	<string.h>
#include	<stdio.h>
#include	"shell.h"
#include	"string_cu.h"
#include	"parse_tree.h"
#include	"get_next_line.h"

void	exec_dbl_redirleft(t_redir *node, int write_fd, char break_loop)
{
  char	*str;

  my_putstr_err("? ");
  str = get_next_line(0, 0);
  if (str)
    {
      write(write_fd, str, strlen(str));
      write(write_fd, "\n", 1);
    }
  while (str != NULL && break_loop)
    {
      my_putstr_err("? ");
      str = get_next_line(0, 0);
      if (str)
	{
	  write(write_fd, str, strlen(str));
	  write(write_fd, "\n", 1);
	  if (strcmp(str, node->name) == 0)
	    break_loop = 0;
	  free(str);
	}
    }
  close(write_fd);
  get_next_line(0, 1);
}

int		dblredir_left(t_redir *node)
{
  int		write_fd;

  write_fd = open("/tmp/42sh_redir", O_RDWR | O_CREAT | O_TRUNC,
		  S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
  if (write_fd != -1)
    exec_dbl_redirleft(node, write_fd, 1);
  write_fd = open("/tmp/42sh_redir", O_RDONLY);
  if (write_fd == -1 || xdup2(write_fd, 0) == -1)
    fprintf(stderr, "Dup. filedescriptor failed.\n");
  close(write_fd);
  return (write_fd);
}

int		redir_left(t_redir *node)
{
  int		fd;
  int		check;

  fd = -1;
  if (node->name)
    {
      if (node->token == 2)
	{
	  check = access(node->name, F_OK);
	  if (check != 0)
	    fprintf(stderr, "%s: Aucun fichier ou dossier de ce type\n",
		    node->name);
	  else
	    {
	      fd = open(node->name, O_RDONLY);
	      if (xdup2(fd, 0) == -1)
		fprintf(stderr, "Dup. filedescriptor failed.\n");
	      else
		close(fd);
	    }
	}
      else if (node->token == 4)
	fd = dblredir_left(node);
    }
  return (fd);
}

int		redir_right(t_redir *node)
{
  int		fd;

  fd = -1;
  if (node->name && (node->token == 1 || node->token == 3))
    {
      if (node->token == 1)
	fd = open(node->name, O_RDWR | O_CREAT, S_IRUSR |
		  S_IWUSR | S_IRGRP | S_IROTH);
      else if (node->token == 3)
	fd = open(node->name, O_RDWR | O_CREAT | O_APPEND, S_IRUSR |
		  S_IWUSR | S_IRGRP | S_IROTH);
      if (xdup2(fd, 1) == -1)
	fprintf(stderr, "Dup. filedescriptor failed.\n");
      else
	close(fd);
    }
  return (fd);
}
