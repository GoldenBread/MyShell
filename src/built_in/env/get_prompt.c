/*
** get_prompt.c for 42sh in /home/alexandre/PSU/PSU_2015_42sh
** 
** Made by Alexandre BARA
** Login   <alexandre@epitech.net>
** 
** Started on Mon May 30 11:22:07 2016 Alexandre BARA
** Last update Thu Jun  2 13:26:47 2016 Thierry LEVISSE
*/

#include	<string.h>
#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	"parsing.h"
#include	"shell.h"

char	*get_prompt(char **env)
{
  char	*prompt;
  char	*username;
  int	i;

  i = find_env("USER", env);
  if (i != -1)
    {
      username = get_env(env[i]);
      prompt = my_xmalloc(strlen(username) + 5);
      prompt[0] = '[';
      prompt[1] = '\0';
      strcat(prompt, username);
      strcat(prompt, "] ");
      free(username);
    }
  else
    {
      prompt = my_xmalloc(4);
      strcpy(prompt, "$> ");
    }
  return (prompt);
}
