/*
** errors.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat Jun  4 14:09:32 2016 Thierry LEVISSE
** Last update Sat Jun  4 14:09:33 2016 Thierry LEVISSE
*/

#include	<stdlib.h>
#include	"parsing.h"
#include	"string_cu.h"

void	exit_errors(int errno)
{
  if (errno == 1)
    my_putstr_err("Error: folder seems to have problems\n");
  else if (errno == 2)
    my_putstr_err("Error: memory allocation\n");
  else if (errno == 3)
    my_putstr_err("Error: open failure on tetrimino file\n");
  exit(errno);
}
