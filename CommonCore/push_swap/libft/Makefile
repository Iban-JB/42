# Define colors using tput
BLACK := $(shell tput setaf 0)
RED := $(shell tput setaf 1)
GREEN := $(shell tput setaf 2)
YELLOW := $(shell tput setaf 3)
BLUE := $(shell tput setaf 4)
MAGENTA := $(shell tput setaf 5)
CYAN := $(shell tput setaf 6)
WHITE := $(shell tput setaf 7)
RESET := $(shell tput sgr0)

# Define Emojis
CHECK := ✅
CROSS := ❌

# Makefile Body
NAME = libft.a

SRCS = ft_isalpha.c \
		ft_isspace.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_striteri.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \
		ft_print_utils.c \
		ft_printf.c

LIBFT = libft/

INCLUDE = libft.h

OBJS_DIR = .objs
OBJS_FILES = $(SRCS_FILES:%.c=%.o)

OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))

OBJS_FILES = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

CC = cc

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@ar rcs $(NAME) $(OBJS)
	@ranlib $@
	@echo "\n$(GREEN)$(LIBFT)$(NAME) created$(RESET)$(CHECK)"

$(OBJS_DIR)/%.o: %.c $(INCLUDE)
	@$(CC) $(CFLAGS) -I /$(INCLUDE) -c $< -o $@
	@echo "$(CYAN) $(LIBFT)$@ Created$(RESET)"


$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "\n$(GREEN)$(LIBFT)$@ Created$(CHECK)$(RESET_COLOR)"


clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RED) $(LIBFT)$(OBJS_DIR) removed$(RESET)$(CROSS)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME) removed$(RESET)$(CROSS)"

re: fclean all

.PHONY: all clean fclean re bonus