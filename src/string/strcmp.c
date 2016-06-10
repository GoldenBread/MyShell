/*
** my_strcmp_varenv.c for strcmpold in /home/wanty_w/rendu/PSU_2015_42sh/lib
** 
** Made by William WANTY
** Login   <wanty_w@epitech.net>
** 
** Started on Thu Jun  2 15:20:46 2016 William WANTY
** Last update Fri Jun 10 02:07:24 2016 Thierry LEVISSE
*/

int	my_strcmp(char *str1, char *str2)
{
  int	i;

  i = 0;
  while (str1[i] != '\0' || str2[i] != '\0')
    {
      if (str1[i] < str2[i])
	return (-1);
      else if (str1[i] > str2[i])
	return (1);
      i++;
    }
  return (0);
}

int	my_strncmp(char *str1, char *str2, int n)
{
  int	i;

  i = 0;
  while ((str1[i] != '\0' || str2[i] != '\0') && i < n)
    {
      if (str1[i] < str2[i])
	return (-1);
      else if (str1[i] > str2[i])
	return (1);
      i++;
    }
  return (0);
}

int	my_strcmp_varenv(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] != '=' && s1[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (-1);
      i++;
    }
  if (s1[i] == '=' && s2[i] == '\0')
    return (0);
  return (-1);
}
