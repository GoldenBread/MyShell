/*
** bzero.c for 42sh in /home/thierry/Github/MyShell/src/string
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun 10 02:15:18 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:15:19 2016 Thierry LEVISSE
*/

void		my_bzero(char *str, unsigned int size)
{
  unsigned int	i;

  i = 0;
  while (i < size)
    {
      str[i] = '\0';
      i++;
    }
}
