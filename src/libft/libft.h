/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwinnink <gwinnink@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:45:03 by gwinnink          #+#    #+#             */
/*   Updated: 2022/11/21 13:16:21 by gwinnink         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <stdbool.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_str_list
{
	char				*str;
	struct s_str_list	*next;
}	t_str_list;

// Libft functions
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_isspace(int c);
void		*ft_memset(void *b, int c, size_t len);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
void		*ft_memcpy(void *dst, const void *src, size_t n);
int			ft_tolower(int c);
int			ft_toupper(int c);
char		*ft_strchr(const char *str, int c);
char		*ft_strrchr(const char *str, int c);
void		ft_bzero(void *s, size_t n);
void		*ft_memmove(void *str1, const void *src, size_t n);
void		*ft_memchr(const void *str, int c, size_t n);
int			ft_strlcat(char *dst, const char *src, size_t size);
int			ft_strlcpy(char *dst, const char *src, size_t size);
int			ft_memcmp(const void *str1, const void *str2, size_t n);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
void		*ft_calloc(unsigned int count, size_t size);
char		*ft_strdup(const char *s1);
char		*ft_substr(const char *s, unsigned int start, size_t len);
char		*ft_strjoin(const char *s1, const char *s2);
char		*ft_strjoin_free(char *s1, char *s2);
char		*ft_strjointhree(const char *s1, const char *s2, const char *s3);
char		*ft_strtrim(const char *s1, const char *set);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		**ft_split(const char *s, char c);
char		*ft_itoa(int n);
char		*ft_strmapi(const char	*s, char (*f)(unsigned int, char));
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
void		*ft_free_all(char **arr);
bool		ft_check_valid_atoi(int *code, char *str);
bool		ft_is_longlong(char *str);

// str list/array functions
t_str_list	*ft_str_list_new(char *str);
void		ft_str_list_add_front(t_str_list **list, t_str_list *new);
void		ft_str_list_free(t_str_list *list);
void		ft_str_list_free_all(t_str_list **head);
char		**ft_str_list_to_arr(t_str_list *list);
t_str_list	*ft_str_arr_to_list(char **arr);

// Libft bonus functions
t_list		*ft_lstnew(void *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
int			ft_lstsize(t_list *lst);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		ft_lstiter(t_list *lst, void (*f)(void *));
t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif