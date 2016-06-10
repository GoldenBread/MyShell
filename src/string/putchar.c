/*
** putchar.c for 42sh in /home/thierry/Github/MyShell/src/string
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun 10 02:23:26 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:23:31 2016 Thierry LEVISSE
*/

#include	<unistd.h>

void		my_putchar(char c)
{
  write(1, &c, 1);
}
