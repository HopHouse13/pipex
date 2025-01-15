/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:09:40 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/15 17:33:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void		ft_free(t_data *data)
{
	int	i;

	i = -1;
	if(data->cmd1.cmd)	
	{
		while(data->cmd1.cmd[++i])
			free(data->cmd1.cmd[i]);
		free(data->cmd1.cmd);
	}
	i = -1;
	if(data->cmd2.cmd)	
	{
		while(data->cmd2.cmd[++i])
			free(data->cmd2.cmd[i]);
		free(data->cmd2.cmd);
	}
	//close infile and outfile if > -1
}

void	ft_close_fd(t_data *data)
{
	if(data->fd_infile)
		close(data->fd_infile);
	if(data->fd_outfile)
		close(data->fd_outfile);
}

