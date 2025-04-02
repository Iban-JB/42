GREEN = $(shell tput setaf 2)
RESET_COLOR = $(shell tput sgr0)
CYAN = $(shell tput setaf 6)
CHECK = ✅

SRCS_FILES = 	ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_strncmp.c \
				ft_atoi.c \
				ft_toupper.c \
				ft_tolower.c \
				ft_strlcat.c \
				ft_strlcpy.c \
				ft_bzero.c \
				ft_memset.c \
				ft_memcpy.c \
				ft_memmove.c \
				ft_calloc.c \
				ft_memcpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_strnstr.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_split.c \
				ft_itoa.c \
				ft_strmapi.c \
				ft_striteri.c \
				ft_putendl_fd.c \
				ft_lstnew_bonus.c \
				ft_lstadd_front_bonus.c \
				ft_lstsize_bonus.c \
				ft_lstlast_bonus.c \
				ft_lstadd_back_bonus.c \
				ft_lstdelone_bonus.c \
				ft_lstclear_bonus.c \
				ft_lstiter_bonus.c \
				ft_lstmap_bonus.c \
				ft_dprintf.c \
				ft_putchar_fd.c \
				ft_putnbr_base_long_fd.c \
				ft_putnbr_fd.c \
				ft_putstr_fd.c \
				ft_strlen.c \
				ft_addstack.c \
				ft_stackfirst.c \
				ft_delstack.c \
				ft_stackinit.c \
				ft_stackfree.c \
				ft_crt_elmnt_stack.c \
				ft_lenstack.c \
				ft_add_front_tab.c \
				ft_del_front_tab.c \
				get_next_line.c \
				get_next_line_utils.c \
				ft_strcpy.c \
				ft_len_tab_str.c \
				ft_strcmp.c

INCS_FILES =	libft.h

OBJS_FILES = $(SRCS_FILES:.c=.o)

DIR_OBJS = .obj
DIR_SRCS = srcs
DIR_INCS = includes

NAME = libft.a

CC = cc

FLAGS = -Werror -Wall -Wextra

OBJS = $(addprefix $(DIR_OBJS)/, $(OBJS_FILES))

SRCS = $(addprefix $(DIR_SRCS)/, $(SRCS_FILES))

INCS = $(addprefix $(DIR_INCS)/, $(INCS_FILES))

all: $(NAME)

$(NAME): $(DIR_OBJS) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@echo "$(GREEN) libft/$(NAME) created$(CHECK)$(RESET_COLOR)"

$(DIR_OBJS)/%.o: $(DIR_SRCS)/%.c $(INCS)
	@$(CC) $(FLAGS) -I $(DIR_INCS) -c $< -o $@
	@echo "$(CYAN) libft/$@ created$(RESET_COLOR)"

clean:
	@rm -rf $(DIR_OBJS)

$(DIR_OBJS):
	@mkdir -p $(DIR_OBJS)

fclean:clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean