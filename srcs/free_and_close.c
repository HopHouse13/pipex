/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:09:40 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/23 13:09:21 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_master_free_and_close(t_data *data)
{
	ft_free_double_tab(data);
	ft_free_tab(data);
	ft_close_fd(data);
}

void	ft_free_tab(t_data *data)
{
	if (data->cmd1.path != NULL)
		free(data->cmd1.path);
	if (data->cmd2.path != NULL)
		free(data->cmd2.path);
}

void	ft_free_double_tab(t_data *data)
{
	int	i;

	i = -1;
	if (data->cmd1.cmd)
	{
		while (data->cmd1.cmd[++i])
			free(data->cmd1.cmd[i]);
		free(data->cmd1.cmd);
	}
	i = -1;
	if (data->cmd2.cmd)
	{
		while (data->cmd2.cmd[++i])
			free(data->cmd2.cmd[i]);
		free(data->cmd2.cmd);
	}
	i = -1;
	if (data->paths_tab)
	{
		while (data->paths_tab[++i])
			free(data->paths_tab[i]);
		free(data->paths_tab);
	}
}

void	ft_close_fd(t_data *data)
{
	if (data->fd_infile > -1)
		close(data->fd_infile);
	if (data->fd_outfile > -1)
		close(data->fd_outfile);
}
