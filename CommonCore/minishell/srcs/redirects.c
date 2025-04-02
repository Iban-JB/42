/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirects.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 11:37:17 by ibjean-b          #+#    #+#             */
/*   Updated: 2024/06/16 14:07:07 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	do_rdr_in(t_file_info *rdr_info, t_gr_coll *gr_coll, t_bool is_child)
{
	int		fd;
	char	*name;

	name = rdr_info->name_file;
	if (rdr_info->error == true)
		return (error_redirection_arg(name, gr_coll, is_child));
	fd = open_gr(gr_coll, open(name, O_RDONLY), is_child);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "%s%s: %s\n", MINISHELL, \
		name, strerror(errno));
		if (is_child == true)
			free_gr_all(gr_coll, 1, true);
	}
	if (is_child == true)
	{
		close_gr(gr_coll, is_child, STDIN_FILENO);
		dup2_gr(gr_coll, fd, STDIN_FILENO, is_child);
	}
	if (fd != -1)
		close_gr(gr_coll, is_child, fd);
	if (fd == -1)
		return (-1);
	return (1);
}

int	do_rdr_out(t_file_info *rdr_info, t_gr_coll *gr_coll, t_bool is_child)
{
	int		fd;
	char	*name;

	name = rdr_info->name_file;
	if (rdr_info->error == true)
		return (error_redirection_arg(name, gr_coll, is_child));
	fd = open_gr(gr_coll, \
	open(name, O_WRONLY | O_TRUNC | O_CREAT, 0777), is_child);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "%s%s: %s\n", \
MINISHELL, name, strerror(errno));
		if (is_child == true)
			free_gr_all(gr_coll, 1, true);
	}
	if (is_child == true)
	{
		close_gr(gr_coll, is_child, STDOUT_FILENO);
		dup2_gr(gr_coll, fd, STDOUT_FILENO, is_child);
		close_gr(gr_coll, is_child, fd);
	}
	if (is_child)
		return (1);
	return (fd);
}

int	do_rdr_append(t_file_info *rdr_info, t_gr_coll *gr_coll, t_bool is_child)
{
	int		fd;
	char	*name;

	name = rdr_info->name_file;
	if (rdr_info->error == true)
		return (error_redirection_arg(name, gr_coll, is_child));
	fd = open_gr(gr_coll, \
	open(name, O_WRONLY | O_CREAT | O_APPEND, 0777), is_child);
	if (fd == -1)
	{
		ft_dprintf(STDERR_FILENO, "%s%s: %s\n", \
MINISHELL, name, strerror(errno));
		if (is_child == true)
			free_gr_all(gr_coll, 1, true);
	}
	if (is_child == true)
	{
		close_gr(gr_coll, is_child, STDOUT_FILENO);
		dup2_gr(gr_coll, fd, STDOUT_FILENO, is_child);
		close_gr(gr_coll, is_child, fd);
	}
	if (is_child)
		return (1);
	return (fd);
}

int	do_rdr_pipe(t_gr_coll *gr_coll, t_pipe_info *p_info)
{
	if (p_info)
	{
		if (!p_info->last)
		{
			dup2_gr(gr_coll, p_info->fd[1], STDOUT_FILENO, true);
			close_gr(gr_coll, true, p_info->fd[1]);
			close_gr(gr_coll, true, p_info->fd[0]);
		}
		if (p_info->temp_fd)
		{
			dup2_gr(gr_coll, p_info->temp_fd, STDIN_FILENO, true);
			close_gr(gr_coll, true, p_info->temp_fd);
		}
	}
	return (0);
}

int	do_redirects(t_cmd_info *full_cmd, t_pipe_info *pipe_info, \
t_gr_coll *gr_coll, t_bool is_child)
{
	int			fd;
	int			error;
	t_list		*lst_rdr;
	t_file_info	*rdr_info;

	do_rdr_pipe(gr_coll, pipe_info);
	fd = 1;
	error = 0;
	lst_rdr = full_cmd->file_info_list;
	while (lst_rdr)
	{
		rdr_info = (t_file_info *)lst_rdr->content;
		if (need_to_close_gr(fd, rdr_info->type_arg))
			close_gr(gr_coll, is_child, fd);
		if (rdr_info->type_arg == infile || rdr_info->type_arg == here_doc)
			error = do_rdr_in(rdr_info, gr_coll, is_child);
		else if (rdr_info->type_arg == outfile)
			fd = do_rdr_out(rdr_info, gr_coll, is_child);
		else if (rdr_info->type_arg == append)
			fd = do_rdr_append(rdr_info, gr_coll, is_child);
		if (fd == -1 || error == -1)
			return (-1);
		lst_rdr = lst_rdr->next;
	}
	return (fd);
}
