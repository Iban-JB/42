/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibjean-b <ibjean-b@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 15:29:59 by rperrot           #+#    #+#             */
/*   Updated: 2024/06/07 17:01:41 by ibjean-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_file_info	*trans_lst_file_info(t_list *lst)
{
	if (lst && lst->content)
		return ((t_file_info *)lst->content);
	return (NULL);
}

t_cmd_info	*trans_lst_cmd_info(t_list *lst)
{
	if (lst && lst->content)
		return ((t_cmd_info *)lst->content);
	return (NULL);
}
