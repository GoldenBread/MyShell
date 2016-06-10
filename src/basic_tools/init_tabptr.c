/*
** init_tabptr.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jun  5 02:13:17 2016 Thierry LEVISSE
** Last update Sun Jun  5 03:16:52 2016 Thierry LEVISSE
*/

#include	<string.h>
#include	"shell.h"

void	init_tabptr(t_data *data)
{
  data->builtins[0].built_in = strdup("setenv");
  data->builtins[0].p = my_setenv;
  data->builtins[1].built_in = strdup("unsetenv");
  data->builtins[1].p = my_unsetenv;
  data->builtins[2].built_in = strdup("exit");
  data->builtins[2].p = my_exit;
  data->builtins[3].built_in = strdup("echo");
  data->builtins[3].p = my_echo;
  data->builtins[4].built_in = strdup("cd");
  data->builtins[4].p = built_cd;
}
