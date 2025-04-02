/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:47:13 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/06 15:42:20 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <fcntl.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_element
{
	int					value;
	struct s_element	*next;
	int					rank;

}	t_element;

typedef struct s_tab_stack
{
	int	*tab_stack;
	int	len;
}	t_tab_stack;

typedef struct s_stack
{
	struct s_element	*first;
}	t_stack;

typedef enum s_bool
{
	false = 0,
	true = 1
}	t_bool;

int				ft_atoi(const char *str);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			ft_bzero(void *s, size_t n);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
void			*ft_memset(void *s, int c, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_calloc(size_t nmem, size_t size);
void			*ft_memcpy(void *dest, const void *src, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memchr(const void *s, int c, size_t n);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *src);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putendl_fd(char *s, int fd);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
void (*del)(void *));
t_stack			*ft_init_stack(void);
void			ft_addstack(t_stack *stack, t_element *new_element);
t_element		*ft_delstack(t_stack *stack);
int				ft_stackfirst(t_stack *stack);
t_stack			*ft_stackinit(void);
void			ft_stackfree(t_stack *stack);
t_bool			ft_crt_elmnt_stack(t_stack *stack, int value);
int				ft_lenstack(t_stack *a, t_stack *b);
void			ft_add_front_tab(t_tab_stack *stack_add, int value);
int				ft_del_front_tab(t_tab_stack *stack_del);
char			*get_next_line(int fd);
char			*ft_strjoin_line(char	*last, char *buffer, size_t	n);
size_t			ft_findnewline(char *s);
void			ft_memzero(char *s, size_t n);
size_t			ft_find_jump(char *s);
char			*ft_create_line(char *last);
void			ft_change_buffer(char *last, char *buffer);
char			*ft_free_line(char *last, char *return_value);
size_t			ft_strlen_line(char *s);
char			*ft_strjoin_three(char const *s1, char const *s2, \
char const *s3);
size_t			ft_findnewline(char *s);
int				ft_dprintf(int fd, const char *s, ...);
int				ft_putchar_fd(char c, int fd);
int				ft_putnbr_fd(int n, int fd);
int				ft_putnbr_base_long_fd(unsigned long long int nb, char *base, \
unsigned long long int len_base, int fd);
size_t			ft_strlen(const char *str);
int				ft_putstr_fd(char *s, int fd);
int				ft_len_number(long int n);
char			*ft_strcpy(char *dest, char *src);
size_t			ft_len_tab_str(char **tab);
int				ft_strcmp(char *s1, char *s2);
t_bool			char_is_number(char *str);
#endif