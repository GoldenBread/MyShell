/*
** string.h for asm in /home/thierry/Rendu/CPE_2015_corewar/asm/src
** 
** Made by Thierry LEVISSE
** Login   <thierry@epitech.net>
** 
** Started on Mon Mar 21 16:00:26 2016 Thierry LEVISSE
** Last update Tue May 31 02:45:59 2016 Thierry LEVISSE
*/

#include	"parsing.h"

#ifndef STRING_H_
# define STRING_H_

int	my_strcmp(char *str1, char *str2);
int	my_strncmp(char *str1, char *str2, int n);
int	my_strbetcmp(char *str1, char *str2, int pos1, int plus);
int	my_strcmp2(char *search, char *s2);
void	my_strcat(char *dest, char *src);
char	*my_strcat_ed(char *str, char *str2);
char	*my_strcat_realloc(char *dest, char *src);
void	my_bzero(char *str, int size);
void	my_putchar(char c);
void	my_putstr(char *str);
void	my_putstr_err(char *str);
int	my_strlen(char *str);
int	my_struntil(char *str, char c, int pos);
void	my_strcpy(char *dest, char *src);
void	my_strcpy_sized(char *dest, char *src, int length);
void	my_strcpy_plus_char(char *dest, char *src);
char	*my_strdup(char *src);
char	*my_strndup(char *src, int n);
char	**str_to_wordtab(char *str);
char	**str_to_wordtab_quote(char *str);
void	disp_darray(char **d_array);
int	my_getnbr(char *str);
int	strdupplusone(char ***arge);
char	*my_allocstrcpy(char *dest, char *src);
void	strn_decalate(char *str, int n);

#endif
