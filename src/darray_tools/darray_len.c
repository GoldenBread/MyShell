/*
** darray_len.c for 42 in /home/thierry/Rendu/PSU_2015_42sh/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Thu Jun  2 02:45:02 2016 Thierry LEVISSE
** Last update Thu Jun  2 02:45:55 2016 Thierry LEVISSE
*/

int	darray_len(char **darray)
{
  int	i;

  i = 0;
  while (darray && darray[i])
    i++;
  return (i);
}
