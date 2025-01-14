/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 11:09:40 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/14 11:35:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free(t_data *data)
{
	int	i;

	i = -1;
	if(data->cmd1.cmd != NULL)	
	{
		while(data->cmd1.cmd[++i])
			free(data->cmd1.cmd[i]);
		free(data->cmd1.cmd);
	}

	i = -1;
	if(data->cmd2.cmd != NULL)	
	{
		while(data->cmd2.cmd[++i])
			free(data->cmd2.cmd[i]);
		free(data->cmd2.cmd);
	}
	//close infile and outfile if > -1
}
