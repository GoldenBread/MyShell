/*
** strcpy.c for 42sh in /home/thierry/Github/MyShell/src/string
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Fri Jun 10 02:17:40 2016 Thierry LEVISSE
** Last update Fri Jun 10 02:17:40 2016 Thierry LEVISSE
*/

void	my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}

void	my_strcpy_sized(char *dest, char *src, int length)
{
  int	i;

  i = 0;
  while (i < length)
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
}

void	my_strcpy_plus_char(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i++;
    }
}
