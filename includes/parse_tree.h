/*
** parse_linked.h for minishell2 in /home/thierry/Rendu/parsems2
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Tue May 10 10:52:28 2016 Thierry LEVISSE
** Last update Sat Jun  4 15:10:22 2016 Thierry LEVISSE
*/

#ifndef PARSE_TREE_H_
# define PARSE_TREE_H_

/*
**	token == 0 argument str
**	token == 1 '>'
**	token == 2 '<'
**	token == 3 '>>'
**	token == 4 '<<'
**	token == 5 '|'
*/

typedef struct	s_node
{
  char		token;
  char		**args_l;
  char		**args_r;
  struct s_node	*up;
  int		root_node;
}		t_node;

typedef struct	s_redir
{
  char		*name;
  char		token;
}		t_redir;

typedef struct	s_tree
{
  t_node	*branch;
  t_redir	redir_st;
  t_redir	redir_nd;
  char		sucess;
  struct s_node	*root;
}		t_tree;

#endif
