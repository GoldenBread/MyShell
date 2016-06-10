/*
** exec_simple.c for 42sh in /home/kania_r/rendu/PSU/42
** 
** Made by Romain KANIA
** Login   <kania_r@epitech.net>
** 
** Started on Mon May 30 11:28:29 2016 Romain KANIA
** Last update Fri Jun 10 02:00:40 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<sys/wait.h>
#include	<string.h>
#include	"shell.h"
#include	"parsing.h"
#include	"parse_tree.h"

void		exec_with_path(char **command, char **env)
{
  int           s;
  int		i;
  int           n;
  char          *buff;

  i = findvar(env, "PATH=");
  n = 5;
  while (i != -1 && env[i][n] != '\0')
    {
      s = 0;
      buff = my_xmalloc(sizeof(char) * (200));
      while (env[i][n] && env[i][n] != ':')
        buff[s++] = env[i][n++];
      buff[s++] = '/';
      buff[s] = '\0';
      strcat(buff, command[0]);
      if (access(buff, F_OK) == 0)
        execve(buff, command, env);
      free(buff);
      if (env[i][n] != '\0')
        n++;
    }
  fprintf(stderr, "%s: Command not found.\n", command[0]);
  exit(1);
}

void		my_exec(char **command, char **env)
{
  if ((searchslash(command[0]) == 1 || searchslash(command[0]) == 2)
      && access(command[0], F_OK) != -1 && command[0] != '\0')
    {
      execve(command[0], command, env);
      exit(0);
    }
  else if (searchslash(command[0]) != 2 && searchslash(command[0]) != 1
           && access(command[0], F_OK) == -1
           && command[0] != '\0')
    exec_with_path(command, env);
  fprintf(stderr, "%s: command not found\n", command[0]);
  exit(1);
}

void	choose_exec(char **command, char ***env)
{
  if (built_check(command))
    my_exec(command, *env);
  exit(0);
}

void		exec(char **command, char ***env, t_tree *tree)
{
  int		sig;
  pid_t		pid;

  redir_left(&tree->redir_st);
  redir_left(&tree->redir_nd);
  if ((pid = fork()) == -1)
    fail_syscall("Fail to create processus\n");
  if (pid == 0)
    choose_exec(command, env);
  else
    {
      waitpid(pid, &sig, 0);
      if (WIFEXITED(sig) != 1 || WEXITSTATUS(sig) != 0)
	tree->sucess = 1;
      printsig(sig);
    }
}

void	       checkiftoken(t_tree *tree, char ***env)
{
  if (tree && tree->root && tree->root->token != 5 &&
      tree->root->args_l)
    exec(tree->root->args_l, env, tree);
}
