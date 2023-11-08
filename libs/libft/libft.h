/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsuomins <fsuomins@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 02:57:01 by aqueiroz          #+#    #+#             */
/*   Updated: 2023/11/07 22:01:03 by fsuomins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# ifndef SIZE_MAX
#  define SIZE_MAX 2147483647
# endif
# define BUFFER_SIZE 42

size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t		ft_strlen(const char *str);
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t n);
void		*ft_memset(void *ptr, int value, size_t num);
void		*ft_memchr(const void *s, int c, size_t n);
void		*ft_calloc(size_t count, size_t size);
void		ft_putchar_fd(char c, int fd);
void		ft_bzero(void *s, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strtrim(const char *s1, const char *set);
char		*ft_strjoin(const char *s1, const char *s2);
char		**ft_split(char const *s, char c);
char		*ft_strrchr(const char *s, int c);
char		*ft_strchr(const char *s, int c);
char		*ft_strdup(const char *str);
char		*ft_itoa(int n);
int			ft_is_numeric_string(const char *str);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
int			ft_isprint(int c_is_printable);
int			ft_isalpha(int c_is_a_alpha);
int			ft_isdigit(int c_is_a_digit);
int			ft_isascii(int c_is_a_ascii);
int			ft_isalnum(int c_is_a_alnum);
int			ft_atoi(const char *str);
long double	ft_atof(char *str);
int			ft_tolower(int c);
int			ft_toupper(int c);
int			ft_isupper(int c);
int			ft_islower(int c);
char		*ft_strtok(char *str, const char *c);
int			ft_strcmp(char *str, char *str2);
void		ft_putstr_fd(char *s, int fd);
char		*get_next_line(int fd);

#endif