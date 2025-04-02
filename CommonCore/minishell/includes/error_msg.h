/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 16:08:51 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/11 16:06:39 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERROR_UNEXPECTED_TOKEN "syntax error near unexpected token "
# define ERROR_LINE_NOT_FINISH "this line is not finish"
# define MINISHELL "minishell: "
# define WARNING "warning: " 
# define NO_EXIST ": No such file or directory"
# define NO_PERMS ": Permission denied"
# define TOO_MANY_ARGS ": too many arguments"
# define LINE_NOT_FINISH ": the quotes are not firm"
# define HOME_NOT_SET "cd: HOME not set"
# define INVALID_IDENTIFIER "not a valid identifier"
# define CD "cd"
# define EXPORT "export"
# define ECHO "echo"
# define EXIT "exit"
# define UNSET "unset"
# define PWD "pwd"
# define ENV "env"
# define NO_FOUND ": command not found"
# define NUMERIC_ARG ": numeric argument required"
# define IS_DIR ": Is a directory"
# define AMBIGUOUS_RED ": ambiguous redirect"

typedef enum e_exit_value
{
	EXIT_DUP2_FAIL,
	EXIT_READ_FAIL,
	EXIT_FAIL,
	EXIT_LINE_NOT_FINISH = 100,
	EXIT_CLOSE_FAIL,
	EXIT_PARSING = 2,
	EXIT_WIN = 0,
	EXIT_ACCESS = 1,
	EXIT_OPEN_FAIL = 127
}	t_exit_value;
#endif
