/*
** parsing.h for 42sh in /home/thierry/Rendu/ms2/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Tue May 31 02:43:37 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:11:54 2016 Alexandre BARA
*/

#include	<stdlib.h>
#include	"parse_tree.h"

#ifndef PARSING_H_
# define PARSING_H_

int	ambi_redir(t_tree *tree);

char	**str_to_wordtab_quote(char *str);

void	space_token(char **str);

int	is_token(char *str);

int	check_separator(char *str, int loc, int quote_status);
void	*my_xmalloc(size_t size);
void	exit_errors(int errno);
void	skip_separator(char *str, int *pos);
void	my_realloc(char **str, size_t size);
void	realloc_darray(char ***darray, size_t size);
void	space_token(char **str);
int	check_token(char **darray);
void	free_tree(t_tree *tree);
void	free_darray(char **darray);
void	bnull(char **darray, size_t size);

char	**d_array_dup(char **d_array);
void	darray_to_tree(t_tree **tree, char **darray);
int	ret_token(char *str);

void	disp_darray(char **darray);
void	disp_tree_cmd(t_tree *tree);

int	set_tree(t_tree **tree, char **cmd_str);

char	**str_to_wordtab(char *str);

void	**darray_malloc(size_t x, size_t y, size_t type);

void	my_bzero(char *str, int size);

int	ambiredir(char **wordtab);
int	nbr_redir(char **wordtab, int err);
int	check_name(char **wordtab, int err);
int	check_alone(char **wordtab, int err);
int	check_encounter(char **wordtab, int err);

int	ret_separator(char *cmd_str_raw, int size);
int	ret_value_sep(char sep, char *ret);

#endif
