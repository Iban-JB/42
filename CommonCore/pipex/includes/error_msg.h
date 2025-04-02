/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:22:53 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/03/21 15:21:31 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERR_MSG1 "Invalid use of pipex, please see the example below\n\n \
Ex : ./pipex infile \"cat -e\" \"wc -l\" outfile\n"

# define ERR_MSG2 "pipe() function crashed\n"

# define ERR_MSG3 "ft_split() function crashed\n"

# define ERR_MSG4 "ft_strdup() function crashed\n"

# define ERR_MSG5 "fork() function crashed\n"

# define ERR_MSG6 "ft_strjoin() function crashed\n"

# define PB_MSG1 "PATH could not be found"

# define PB_MSG2 "infile invalid or reading permission not allowed"

# define PB_MSG3 "outfile invalid or writing permission not allowed"

# define PB_MSG4 " : permission to execute not allowed"

# define PB_MSG5 " : could not be found"

# define PB_MSG6 "execve() function crashed"

# define PB_MSG7 "dup2() function crashed"

#endif