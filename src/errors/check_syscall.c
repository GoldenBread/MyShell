/*
** check_syscall.c for 42sh in /home/kania_r/rendu/PSU/42
** 
** Made by Romain KANIA
** Login   <kania_r@epitech.net>
** 
** Started on Mon May 30 13:35:47 2016 Romain KANIA
** Last update Tue May 31 03:34:18 2016 Thierry LEVISSE
*/

#include	<unistd.h>
#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>
#include	<parsing.h>

void		fail_syscall(char *error)
{
  fprintf(stderr, "%s\n", error);
  exit(EXIT_FAILURE);
}
