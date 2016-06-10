/*
** separator.c for 42sh in /home/thierry/Rendu/PSU_2015_42sh
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Sat Jun  4 15:59:31 2016 Thierry LEVISSE
** Last update Sun Jun  5 13:12:08 2016 Alexandre BARA
*/

int	cmp_next(char *cmd_str_raw, int cur, char c)
{
  if (cmd_str_raw[cur] == c && cmd_str_raw[cur + 1] == c)
    return (0);
  return (1);
}

int	ret_separator(char *cmd_str_raw, int size)
{
  if (cmd_str_raw[size] == ';')
    return (1);
  else if (!cmp_next(cmd_str_raw, size, '|'))
    return (2);
  else if (!cmp_next(cmd_str_raw, size, '&'))
    return (3);
  return (0);
}

int	ret_value_sep(char sep, char *ret)
{
  if ((*ret == 0 && sep == 2) ||
      (*ret == 1 && sep == 3) ||
      (*ret == 2 && sep != 1))
    {
      *ret = 2;
      return (1);
    }
  if (sep == 1)
    *ret = 0;
  return (0);
}
