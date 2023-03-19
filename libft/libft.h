/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hateisse <hateisse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 05:28:13 by hateisse          #+#    #+#             */
/*   Updated: 2023/03/19 17:46:02 by hateisse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H
# include <stddef.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strsjoin(unsigned int count, ...);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_utoa(unsigned int n);
char	*ft_ctos(unsigned char c);
char	*ft_ultobase(unsigned long n, short base);
int		ft_atoi(const char *nptr);
long	ft_atol(const char *nptr);
long	ft_strtol(const char *nptr, const char **endptr, int base);
int		ft_strtoi(const char *nptr, const char **endptr, int base);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr(const char *s);
void	ft_putnstr(const char *s, size_t n);
int		ft_intchr(int n, int *tab, int tabsize);
int		ft_isalpha(int c);
int		ft_isupper(int c);
int		ft_islower(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);

void	ft_strtoupper(char *s);
int		ft_toupper(int c);
int		ft_tolower(int c);

char	*ft_strcpy(char *dest, const char *src);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strncat(char *dest, const char *src, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strcasencmp(const char *s1, const char *s2, size_t n);
int		ft_strcasecmp(const char *s1, const char *s2);

size_t	ft_strlen(const char *s);
int		ft_strslen(char **strs);
char	*ft_strchr(const char *s, int c);
char	*ft_strnchr(const char *s, size_t count, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchrnul(const char *s, int c);
char	*ft_strstr(const char *haystack, const char *needle);
char	*ft_strcasestr(const char *haystack, const char *needle);
char	*ft_strnstr(const char *big, const char *little, size_t len);

size_t	ft_intlen(int n);
size_t	ft_ulonglen(unsigned long n);
size_t	ft_uintlen(unsigned int n);

void	*ft_memset(void *s, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(const char *s);
void	ft_strsfree(char **strs);

t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

void	ft_print_array_str(char **array);

#endif
