/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:08:33 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/12 14:29:52 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "libft.h"
# include "error_msg.h"
# include <stdlib.h>
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "garbage_collector.h"

# define FILE_RANDOM "/dev/urandom"
# define DEFAULT_PATH "/usr/local/sbin /usr/local/bin /usr/sbin \
/usr/bin /sbin /bin /usr/games /usr/local/games /snap/bin"
# define HOME "HOME"
# define PWD_ENV "PWD"
# define OLDPWD "OLDPWD"
# define PATH_MAX 4096
# define DOS_TMP "/var/tmp/minishell_"

extern int					g_sig;
typedef struct s_gr_coll	t_gr_coll;

typedef enum e_type_arg
{
	infile,
	outfile,
	here_doc,
	append,
	pipe_char,
	other
}	t_type_arg;

typedef struct s_file_info
{
	t_type_arg	type_arg;
	char		*name_file;
	t_bool		error;
}	t_file_info;

typedef struct s_pipe_info
{
	int	last;
	int	temp_fd;
	int	fd[2];
}	t_pipe_info;

typedef struct s_cmd_info
{
	char	*cmd;
	char	**argv;
	t_list	*file_info_list;
}	t_cmd_info;

typedef struct s_info_crt_cmd
{
	t_bool		cmd_empty;
	t_type_arg	before_arg;
	char		*line;
	char		*arg;
	int			*start_end;
	char		**envp;
	int			exit_value;
	t_gr_coll	*gr_coll;
	int			end;
}	t_info_crt_cmd;

typedef struct s_data
{
	t_list	*type_data;
	char	**env;
}	t_data;

typedef struct s_parsing
{
	t_bool	simple_quote;
	t_bool	double_quotes;
	char	*line;
}	t_parsing;

typedef struct s_minishell_info
{
	t_exit_value	exit_value;
	t_parsing		*parsing_info;
	t_list			*type_data;
	char			**env;
	t_gr_coll		*gr_coll;
	t_bool			error;
}	t_minishell_info;

typedef enum s_builtins
{
	cd,
	ext,
	pwd,
	unset,
	export,
	env,
	echo,
	not_builtin
}	t_builtins;

char			*get_arg_line(t_info_crt_cmd *info_crt_cmd);
void			parse_line(t_minishell_info *minishell_info);
void			execute_line(t_minishell_info *shell_info, t_list *lst_cmds);
t_bool			create_new_error(char *msg_error, char *msg, int *start_end);
t_parsing		*init_parsing(t_parsing *parsing, t_gr_coll *gr_coll);
void			remove_quotes(t_parsing *parsing_info);
t_list			*crt_lst_cmd(char *line, t_minishell_info *minishell_info);
int				find_end_quotes(char *line, int i);
int				is_special_char(char *c);
t_exit_value	add_info_cmd(t_list **cmd, t_info_crt_cmd *info_crt_cmd);
int				*find_next_arg(char *line, int i, t_gr_coll *gr_coll);
void			free_file_info(void *file_info, t_gr_coll *gr_coll, \
t_bool is_child);
char			**create_pattern(t_info_crt_cmd *info_crt_cmd);
void			free_tab_str(char **tab, int size, \
t_gr_coll *gr_coll, t_bool is_child);
char			**add_str_double_tab(char **argv, char *name, \
t_gr_coll *gr_coll, t_bool is_child);
t_exit_value	add_argv_cmd_in_cmd(t_list **cmd, \
t_info_crt_cmd *info_crt_cmd);
int				find_len_pattern(char *line, int *start_end, \
t_info_crt_cmd *info_crt_cmd);
int				find_len_name_var(char *name, int *i);
char			*find_var_env(char **env, char *name_var, int len_name_var);
void			free_cmd_info(void *cmd_info_base, t_gr_coll *gr_coll, \
t_bool is_child);
t_exit_value	add_cmd_or_file(t_list *last_cmd, \
t_info_crt_cmd *info_crt_cmd, t_type_arg before_arg);
t_list			*create_cmd_info(t_gr_coll *gr_coll);
t_bool			read_here_doc(char *limiter, char **name, \
t_minishell_info *minishell_info);
pid_t			create_child(t_minishell_info *shell_info, \
t_cmd_info *cmd_info, t_pipe_info *pipe_info);
t_file_info		*trans_lst_file_info(t_list *lst);
t_cmd_info		*trans_lst_cmd_info(t_list *lst);
t_exit_value	add_file_temp_lst(t_list *lst_cmd, \
t_minishell_info *minishell_info);
char			*modif_line_heredoc(char *readline, t_bool has_quote, \
t_minishell_info *minishell_info);
int				len_var(int *i, char *line, char **envp, int exit_value);
t_bool			has_quote_limiter(char *limiter);
int				fill_pattern_var(int *i, char *line, \
t_info_crt_cmd *info_crt_cmd, char *pattern);
t_bool			cmp_here_doc_line(char *here_doc, char *limiter);
char			**cp_envp(char **envp, t_gr_coll *gr_coll);
t_bool			line_is_empty(char *line);
int				ft_cd(char **argv, t_minishell_info *shell_info, \
t_bool is_child);
int				change_value_var_env(char *name, char *value, \
t_minishell_info *minishell_info, t_bool is_child);
int				find_id_var_env(char **env, char *name_var, int len_name_var);
char			**unset_var_env(char *name, char **env, \
t_minishell_info *minishell_info, t_bool is_child);
int				ft_env(char **env, int fd);
int				ft_pwd(int fd, char **envp);
int				ft_echo(char **argv, int fd);
int				ft_unset(t_minishell_info *minishell_info, \
char **name, t_bool is_child);
char			*strdup_gr(const char *s, t_gr_coll *gr_coll, t_bool is_child);
int				ft_export(t_minishell_info *minishell_info, \
char **name, t_bool is_child);
t_list			*lstnew_gr(void *content, t_gr_coll *gr_coll);
void			ft_lstclear_gr(t_list **lst, \
void (*del)(void*, t_gr_coll*, t_bool), t_gr_coll *gr_coll, t_bool is_child);
void			ft_lstdelone_gr(t_list *lst, \
void (*del)(void*, t_gr_coll*, t_bool), t_gr_coll *gr_coll, t_bool is_child);
int				do_redirects(t_cmd_info *full_cmd, \
t_pipe_info *pipe_info, t_gr_coll *gr_coll, t_bool is_child);
t_bool			try_to_access(char *path_cmd, char *name);
char			**ft_split_gr(t_gr_coll *gr_coll, char const *s, char c);
char			*ft_strjoin_gr(t_gr_coll *gr_coll, char const *s1, \
char const *s2, t_bool is_child);
t_bool			check_error_first_arg(t_minishell_info *minishell_info);
int				ft_exit(t_minishell_info *shell_info, t_bool is_child, \
int value_return, char **argv);
char			*find_path_command(t_minishell_info *shell_info, char *name);
int				exec_buitlin(t_minishell_info *shell_info, t_cmd_info *cmd, \
t_bool is_child);
void			sig_quit_action(int signal);
void			sig_int_after_exec(int signal);
void			sig_newline(int a);
void			check_directory_perms(t_minishell_info *shell_info, char *name);
char			**ft_split_pattern(t_gr_coll *gr_coll, char const *s);
void			sig_here_doc(int signal);
int				rl_hook_function(void);
t_bool			need_to_close_gr(int fd, t_type_arg ty_a);
int				error_redirection_arg(char *name, t_gr_coll *gr_coll, \
t_bool is_child);
void			next_space(int *i, char const *s);
void			find_len_string(int *i, int *len_new_s, \
const char *s, char *new_s);
void			next_string(int *i, char const *s);
t_builtins		is_builtin(char *name);
int				only_n_flags(char **str_flags);
int				fill_itoa(int n, char *s);
#endif