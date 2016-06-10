/*
** shell.h for 42 in /home/goutas_h/rendu/PSU_2015_42sh
** 
** Made by Hadrien GOUTAS
** Login   <goutas_h@epitech.net>
** 
** Started on Mon May 30 10:22:18 2016 Hadrien GOUTAS
** Last update Fri Jun 10 02:10:05 2016 Thierry LEVISSE
*/

#ifndef SHELL_H_
# define SHELL_H_

#include	<unistd.h>
#include	"parse_tree.h"

typedef struct	s_data t_data;

typedef struct	s_tabptr
{
  char		*built_in;
  void		(*p)(char **cmd, t_data *data);
}		t_tabptr;

struct		s_data
{
  char		**env;
  char		*cdm;
  char		*gnl;
  char		sep;
  int		cnt;
  int		echo;
  char		*oldpwd;
  char		sign[7];
  char		**echo_cmd;
  unsigned char	exit_value;
  t_tabptr	builtins[5];
};

int	varexist(char *, char **);
void	put_default_path(t_data *data);

void	ftab(char **);
void	free_misc(char *cmd_str, t_data *data);
void	exec(char **, char ***, t_tree *);

void	my_exec(char **, char **);
void	fail_syscall(char *);

void	printsig(int sig);

char	*get_prompt(char **env);

int	find_env(char *needle, char **env);
char	*get_env(char *var_env);
int	my_strcmp_varenv(char *s1, char *s2);
void	launch_print_env(t_node *node, char **env);
void	my_unsetenv(char **cmd_tab, t_data *data);
void	my_setenv(char **cmd_tab, t_data *data);
void	my_set_null(char *env);
void	print_env(char **env);
int	modif_env(char **cmd_tab, char ***env);
void	replace_env(char ***env, int i);
int	check_char_setenv(char **cmd_tab);

int	built_check(char **command);
void	scan_built(t_tree *tree, t_data *data);
int	built_launch(char **command, t_data *data);
void	pipe_it(t_tree *tree, char ***env);
void	do_pipe(t_tree *tree, int *pipes, char ***arge, int *cur);
int	get_nbr_piped_args(t_tree *tree);
void	close_pipes(int *pipefd, int nbr_pipes);
int	prep_pipefd(int *pipefd, int nbr_pipes);
char	**get_cmd(t_tree *tree, int nbr_cmd);
int	redir(t_node *node);
int	darray_len(char **darray);

void	checkiftoken(t_tree *tree, char ***env);

int	redir_left(t_redir *node);
int	redir_right(t_redir *node);
void	get_redir(char **wordtab, t_tree *tree);
void	clean_redir(char **wordtab);

void	choose_exec(char **command, char ***env);

int	xdup(int fildes);
int	xdup2(int fildes, int fildes2);

void	my_exit(char **cmd, t_data *data);
int	check_nbr(char *str);
void	strn_delay(char *str, int n);

void	built_cd(char **cmd, t_data *data);
void	init_oldpwd(t_data *data);
char	*current_wd();
char	*getvarenv(char *var, char **arge);

void	echo_disp_loop(char **tab, t_data *data, int y);
void	init_echo(t_data *data);
void	my_echo(char **tab, t_data *data);
void	echo_loop(t_data *data, char *cmd_str);
char	*epur_quote(char *str);
char	**my_quote_to_wordtab(char *str);
void	checkbackslash(char c, int echo, t_data *data);

void	init_tabptr(t_data *data);

void	str_put_back(char *str, int n);
void	normal_quit(char **arge, t_data *data);
int	handle_cmd_str(char **cmd_str, char *cmd_str_raw);
void	core_exec(t_tree *tree, t_data *data);
void	var_existing(t_data *data);

int	searchslash(char *command);
int	findvar(char **env, char *var);

#endif /* !SHELL_H_ */
