/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alessa <alessa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 15:19:42 by danisanc          #+#    #+#             */
/*   Updated: 2022/01/13 11:41:44 by alessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFFER 5000

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/////////////////////////////////
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *b, int c, size_t len);
////The memset() function fills the first n bytes of the
//       memory area pointed to by b with the  constant  byte
//       c.
void	ft_bzero(void *s, int n);
//   The  bzero()  function  erases  the data in the n bytes of the
//   memory starting at the location pointed to by  s,  by  writing
//   zeros (bytes containing '\0') to that area.
void	*ft_memcpy(void *dst, const void *src, size_t n);
//   The  memcpy()  function copies n bytes from memory area src to
//   memory area dest.  The memory areas  must  not  overlap.   Use
//   memmove(3) if the memory areas do overlap.
void	*ft_memmove( void *dst, const void *src, size_t len);
size_t	ft_strlcpy(char	*dst, const char	*src, size_t dstsize);
size_t	ft_strlcat( char	*dst, const char	*src, size_t dstsize);
int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strnstr(const char	*haystack, const char *needle, size_t len);
int		ft_atoi(const char *str);
void	*ft_calloc(int count, int size);
char	*ft_strdup(const char *s1);
//   The  strdup() function returns a pointer to a new
//   string which is a  duplicate  of  the  string  s.
//   Memory  for  the new string is obtained with mal‐
//   loc(3)
//////////////////////////////////////////
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
////////////////////////////////////////////
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void*), void (*del)(void *));
#endif