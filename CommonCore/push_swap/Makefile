# Define colors using tput
BLACK = $(shell tput setaf 0)
RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
YELLOW = $(shell tput setaf 3)
BLUE = $(shell tput setaf 4)
MAGENTA = $(shell tput setaf 5)
CYAN = $(shell tput setaf 6)
WHITE = $(shell tput setaf 7)
RESET_COLOR = $(shell tput sgr0)


# Define styles for text
BOLD = $(shell tput bold)
ITALIC = $(shell tput sitm)

# Define Emojis
CHECK = ✅
CROSS = ❌


# Proram name
NAME = push_swap


# Shortcuts for objects, sources and header files
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
INCS = $(addprefix $(INCS_DIR)/, $(INCS_FILES)) $(LIBFT)


# All Directories
OBJS_DIR = .objs
SRCS_DIR = srcs
INCS_DIR = includes


# All sources so *.c files and 
# all objects files so *.o and 
# includes files so *.h
OBJS_FILES = $(SRCS_FILES:%.c=%.o)

SRCS_FILES =	main.c \
				parsing.c \
				parsing_utils.c \
				check_utils.c \
				solver_utils_a_to_b.c \
				solver_utils_b_to_a.c \
				do_movements.c \
				movements_part_1.c \
				movements_part_2.c \
				movements_part_3.c \
				utils.c \
				stack_utils_part_1.c \
				stack_utils_part_2.c \
				solver.c \
				best_movements.c


INCS_FILES = push_swap.h


# libft is my library
LIBFT = libft/libft.a

# All compilation flags
CFLAGS = -Wall -Wextra -Werror #Useful flags: -g3 -fsanitize=address
IFLAGS = -I includes \
		 -I libft

# Compiler to use
CC = cc
CLANG = clang

# All rules
all: $(LIBFT) $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS) $(INCS)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
	@echo "\n$(GREEN)$(NAME) created$(CHECK)$(RESET_COLOR)"

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c $(INCS)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $(word 1,$^) -o $@
	@echo "$(CYAN) $@ created$(RESET)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(GREEN)$@ created$(CHECK)$(RESET_COLOR)"

$(LIBFT):
	@make -C ./libft -s


norm:
	@norminette includes srcs

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RESET_COLOR)$(RED)$(OBJS_DIR) removed$(CROSS)$(RESET_COLOR)"
	@make clean -C ./libft -s

fclean: clean
	@rm -rf $(NAME)
	@echo "$(RED)$(NAME) removed$(CROSS)$(RESET_COLOR)"
	@make fclean -C ./libft -s

re: fclean all

.PHONY: all clean fclean re norm