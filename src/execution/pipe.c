/*
** pipe.c for pipes in /home/goutas_h/rendu/zimbabwe
** 
** Made by Hadrien GOUTAS
** Login   <goutas_h@epitech.net>
** 
** Started on Mon May 30 11:14:12 2016 Hadrien GOUTAS
** Last update Sun Jun  5 22:04:52 2016 Thierry LEVISSE
*/

#include	<sys/types.h>
#include	<sys/wait.h>
#include	<stdlib.h>
#include	<stdio.h>
#include	"shell.h"
#include	"parse_tree.h"

void	pipe_lredir(int *cur, t_tree *tree)
{
  if (*cur == 0)
    {
      redir_left(&tree->redir_st);
      redir_left(&tree->redir_nd);
    }
}

void	recur_pipe(t_tree *tree, int *pipes, char ***arge, int *cur)
{
  *cur += 1;
  do_pipe(tree, pipes, arge, cur);
}

void	do_pipe(t_tree *tree, int *pipes, char ***arge, int *cur)
{
  int	i;
  char	**exec_it;

  if (*cur < get_nbr_piped_args(tree))
    {
      exec_it = get_cmd(tree, *cur);
      if (fork() == 0)
	{
	  if (*cur != 0)
	    xdup2(pipes[(*cur) * 2 - 2], 0);
	  if (*cur != get_nbr_piped_args(tree) - 1)
	    xdup2(pipes[(*cur) * 2 + 1], 1);
	  i = 0;
	  while (i < (get_nbr_piped_args(tree) - 1) * 2)
	    {
	      close(pipes[i]);
	      i++;
	    }
	  pipe_lredir(cur, tree);
	  choose_exec(exec_it, arge);
	  exit(0);
	}
      else
	recur_pipe(tree, pipes, arge, cur);
    }
}

void		pipe_it(t_tree *tree, char ***env)
{
  int		pipefd[(get_nbr_piped_args(tree) - 1) * 2];
  int		nbr_pipes;
  int		cur;
  int		i;
  int		status;

  cur = 0;
  nbr_pipes = get_nbr_piped_args(tree);
  if (prep_pipefd(pipefd, nbr_pipes) != 1)
    {
      do_pipe(tree, pipefd, env, &cur);
      close_pipes(pipefd, nbr_pipes);
      tree->branch = tree->root;
      i = 0;
      while (i < get_nbr_piped_args(tree))
	{
	  wait(&status);
	  if (WIFEXITED(status) != 1)
	    tree->sucess = 1;
	  printsig(status);
	  i++;
	}
    }
}
