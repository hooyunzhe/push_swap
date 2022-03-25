#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

size_t	ft_strlen(const char *s);
size_t	ft_strslen(char **strs);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		ft_isnum(char *str);
char	*ft_strjoin(const char *s1, const char *s2);
char	**ft_split(const char *s, char c);
void	ft_putstr(char *str, int freeable);
long	ft_atol(const char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrimchr(const char *str, char c);
char	*ft_strupdate(char *s1, const char *s2);

#endif
