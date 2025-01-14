/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 15:44:43 by pbret             #+#    #+#             */
/*   Updated: 2025/01/14 12:18:50 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

// getpid() -> recupere le pid sur processus ou nous sommes.

void	ft_start_pipex(t_data *data)
{
	int pipe_fd[2];
	int	status;
	
	if (pipe(pipe_fd) == -1)
	{
		ft_errors_handle(4);
		return;
	}
	if (ft_fork_in(data, pipe_fd))
		ft_fork_out(data, pipe_fd);
	waitpid(data->cmd1.pid, &status);
	waitpid(data->cmd2.pid, &status);
}

int	ft_fork_in(t_data *data, int *pipe_fd)
{
	data->cmd1.pid = fork();
	if (data->cmd1.pid < 0)
	{
		ft_errors_handle(5);
		return (FAILURE);
	}
	if (data->cmd1.pid == 0)
	{
	 Close(pipe_fd[])
	}
	return(SUCCESS);
}

int	ft_fork_out(t_data *data, int *pipe_fd)
{
	int	status;
	
	waitpid(data->cmd1.pid, &status);
	data->cmd2.pid = fork();
	if (data->cmd2.pid == 0)
	{
	
	}
	return(SUCCESS);
}
