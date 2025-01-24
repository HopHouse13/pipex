/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/23 13:16:08 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_exec_pipex(t_data *data)
{
	int	pipe_fd[2];

	if (pipe(pipe_fd) == -1)
		return (ft_errors_handle(6));
	data->cmd1.pid = fork();
	if (data->cmd1.pid == -1)
		return (ft_errors_handle(7));
	if (data->cmd1.pid == 0)
		ft_first_cmd(data, pipe_fd);
	data->cmd2.pid = fork();
	if (data->cmd2.pid == -1)
		return (ft_errors_handle(8));
	if (data->cmd2.pid == 0)
		ft_second_cmd(data, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(data->cmd1.pid, NULL, 0);
	waitpid(data->cmd2.pid, NULL, 0);
}

void	ft_first_cmd(t_data *data, int *pipe_fd)
{
	if (dup2(data->fd_infile, 0) < STDIN_FILENO)
		ft_errors_handle(9);
	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		ft_errors_handle(9);
	close(data->fd_infile);
	close(data->fd_outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execve(data->cmd1.path, data->cmd1.cmd, data->env) < 0)
		ft_errors_handle(10);
}

void	ft_second_cmd(t_data *data, int *pipe_fd)
{
	if (dup2(pipe_fd[0], 0) < STDIN_FILENO)
		ft_errors_handle(9);
	if (dup2(data->fd_outfile, STDOUT_FILENO) < 0)
		ft_errors_handle(9);
	close(data->fd_infile);
	close(data->fd_outfile);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	if (execve(data->cmd2.path, data->cmd2.cmd, data->env) < 0)
		ft_errors_handle(10);
}
