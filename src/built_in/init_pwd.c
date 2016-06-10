/*
** init_pwd.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jun  5 01:10:36 2016 Thierry LEVISSE
** Last update Sun Jun  5 21:54:52 2016 Thierry LEVISSE
*/

#include	"string_cu.h"
#include	"shell.h"
#include	"parsing.h"

void	init_oldpwd(t_data *data)
{
  data->oldpwd = my_xmalloc(512);
  my_bzero(data->oldpwd, 512);
  getcwd(data->oldpwd, 512);
}

char	*current_wd()
{
  char	*path;

  path = my_xmalloc(512);
  my_bzero(path, 512);
  getcwd(path, 512);
  return (path);
}
