/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mabdelma <mabdelma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:57:34 by mabdelma          #+#    #+#             */
/*   Updated: 2024/01/24 20:19:53 by mabdelma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdarg.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

void	ft_error(char *message, int err);
void	ft_putendl_fd(char *s, int fd);
char	*get_next_line(int fd);
char	*ft_strchr(char const *s, int c);
char	*ft_strdup(char *src);
size_t	ft_strlcat(char *d, const char *s, size_t n);
size_t	ft_strlcpy(char *d, const char *s, size_t n);
size_t	ft_strlen(char const *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strrchr(char const *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strnstr(const char *str, const char *to_find, int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_m(char *stash, char *buffer);
char	**ft_split(char	const *str, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_freeall(void **double_ptr);
bool	ft_isalnum(int c);
bool	ft_isalpha(int c);
bool	ft_isascii(int c);
bool	ft_isdigit(int c);
bool	ft_isprint(int c);
bool	ft_iswhitespace(char c);

#endif
