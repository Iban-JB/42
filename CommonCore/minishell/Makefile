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
NAME = minishell

# Shortcuts for objects, sources and header files
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(addprefix $(OBJS_DIR)/, $(OBJS_FILES))
INCS = $(addprefix $(INCS_DIR)/, $(INCS_FILES))


# All Directories
OBJS_DIR = .objs
SRCS_DIR = srcs
INCS_DIR = includes


# All sources so *.c files and 
# all objects files so *.o and 
# includes files so *.h
SRCS_FILES = main.c \
			 parsing.c \
			 execution.c \
			 init_parsing.c \
			 parsing_quotes.c \
			 error.c \
			 free_minishell_info.c \
			 check_error_line.c \
			 create_lst_cmd.c \
			 find_next_arg.c \
			 add_str_double_tab.c \
			 create_lst_cmd2.c \
			 create_pattern.c \
			 len_pattern.c \
			 here_doc.c \
			 redirects.c \
             utils.c \
             path.c \
             child.c \
             add_file_temp_lst.c \
             transform_lst.c \
             modif_line_here_doc.c \
             cp_envp.c \
             line_is_empty.c \
             ft_cd.c \
             env.c \
             builtins.c \
             malloc_gr.c \
             ft_strdup_gr.c \
             lstnew_gr.c \
             gr_fd.c \
             ft_lstclear_gr.c \
             lst_delone_gr.c \
			 ft_split_gr.c \
			 ft_export.c \
			 ft_strjoin_gr.c \
			 signal.c \
			 add_node.c \
			 expand_flags.c \
			 expand_flags_utils.c \
			 exec_builtins.c

OBJS_FILES = $(SRCS_FILES:c=o)

INCS_FILES = minishell.h \
			 garbage_collector.h \
			 error_msg.h

# libft is my library
LIBFT = libft/libft.a

# All compilation flags
CFLAGS = -Wall -Wextra -Werror #Useful flags: -g3 -fsanitize=address
IFLAGS = -I includes \
		 -I libft/includes

READLINE_FLAGS = -lreadline

# Compiler to use
CC = cc
CLANG = clang

# All rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME) $(READLINE_FLAGS)
	@echo "\n$(GREEN) $(NAME) created$(CHECK)$(RESET_COLOR)"

$(OBJS_DIR)/%.o:   $(SRCS_DIR)/%.c $(INCS)  | $(OBJS_DIR)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $(word 1,$^) -o $@
	@echo "$(CYAN) $@ created$(RESET_COLOR)"

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)
	@echo "$(GREEN)$@ created$(CHECK)$(RESET_COLOR)"

$(LIBFT): FORCE
	@make -C ./libft -s

norm:
	@norminette includes srcs libft

clean:
	@rm -rf $(OBJS_DIR)
	@echo "$(RESET_COLOR)$(RED)$(OBJS_DIR) removed$(RESET_COLOR)"
	@make clean -C ./libft -s

fclean: clean
	@rm -rf $(NAME) $(LIBFT)
	@echo "$(RED)$(LIBFT) removed$(RESET_COLOR)"
	@echo "$(RED)$(NAME) removed$(RESET_COLOR)"

FORCE:

re: fclean all

.PHONY: all clean fclean re norm FORCE
