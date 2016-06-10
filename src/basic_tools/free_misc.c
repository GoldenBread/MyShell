/*
** free_misc.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sun Jun  5 21:46:28 2016 Thierry LEVISSE
** Last update Sun Jun  5 21:50:33 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	<string.h>
#include	"shell.h"

void	free_misc(char *cmd_str, t_data *data)
{
  if (cmd_str && strlen(cmd_str) == 0)
    {
      free(cmd_str);
      free(data->echo_cmd);
    }
}
