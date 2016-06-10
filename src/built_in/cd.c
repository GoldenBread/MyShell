/*
** cd.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jun  5 00:44:21 2016 Thierry LEVISSE
** Last update Sun Jun  5 21:56:31 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<errno.h>
#include	"string_cu.h"
#include	"shell.h"

void	putnf(char *str, t_data *data)
{
  if (errno == EACCES)
    fprintf(stderr, "%s: Permission non accordée.\n", str);
  else
    fprintf(stderr, "%s: Aucun fichier ou dossier de ce type\n", str);
  data->exit_value = 1;
}

void	cd_setenv(t_data *data, char *path)
{
  char	*cmd[4];

  cmd[0] = strdup("setenv");
  cmd[1] = strdup("PWD");
  cmd[2] = path;
  cmd[3] = NULL;
  my_setenv(cmd, data);
}

void	built_cd_update_path(int ret, char *path, t_data *data)
{
  if (ret != -1)
    {
      free(data->oldpwd);
      data->oldpwd = my_strdup(path);
      free(path);
      path = my_xmalloc(512);
      getcwd(path, 512);
      cd_setenv(data, path);
      free(path);
    }
}

int	args_built_cd(char **cmd)
{
  int	cmp;

  cmp = strcmp(cmd[0], "cd");
  if (cmp == 0 && darray_len(cmd) > 2)
    {
      my_putstr_err("cd: Too many arguments.\n");
      return (1);
    }
  else if (cmp != 0)
    return (1);
  return (0);
}

void	built_cd(char **cmd, t_data *data)
{
  char	*path;
  int	ret;

  errno = 0;
  ret = -1;
  if (cmd && args_built_cd(cmd) == 0)
    {
      path = current_wd();
      if (cmd[1] == NULL || strcmp("~", cmd[1]) == 0)
	if (getvarenv("HOME", data->env) != NULL)
	  {
	    if ((ret = chdir(getvarenv("HOME", data->env))) != 0)
	      putnf(getvarenv("HOME", data->env), data);
	  }
	else
	  my_putstr_err("cd: No home directory.\n");
      else if (my_strcmp("-", cmd[1]) == 0)
	{
	  if ((ret = chdir(data->oldpwd)) != 0)
	    putnf(data->oldpwd, data);
	}
      else if ((ret = chdir(cmd[1])) != 0)
	putnf(cmd[1], data);
      built_cd_update_path(ret, path, data);
    }
}
