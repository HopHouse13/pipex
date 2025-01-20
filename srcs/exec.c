/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/20 20:44:52 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

// getpid() -> recupere le pid sur processus ou nous sommes.

void	ft_exec_pipex(t_data *data)
{
	int pipe_fd[2];
	
	if (pipe(pipe_fd) == -1)
		return (ft_errors_handle(7));
	data->cmd1.pid = fork();
	if (data->cmd1.pid == -1)
		return (ft_errors_handle(8));
	if (data->cmd1.pid == 0)
		ft_first_child(data, pipe_fd);
	waitpid(data->cmd1.pid, NULL);
	data->cmd2.pid = fork();
	if (data->cmd2.pid == -1)
		return (ft_errors_handle(9));
	if (data->cmd2.pid == 0)
		ft_second_child(data, pipe_fd);
	waitpid(data->cmd2.pid, NULL);
}
void	ft_first_child(t_data *data, int *pipe_fd)
{
	close(pipe_fd[0]);
	if (dup2(data->fd_infile, 0) < 0)	
		ft_errors_handle(10);
	if (dup2(1, pipe_fd[1]) < 0)	
		ft_errors_handle(10);
	if (execve(data->cmd1.path, data->cmd1.cmd, data->env) < 0)
		ft_errors_handle(11);
}

void	ft_second_child(t_data *data, int *pipe_fd)
{
	close(pipe_fd[1]);
	close(0);
	if (dup2(pipe_fd[0], 0) < 0)
		ft_errors_handle(10);
	if (dup2(1, data->fd_outfile) < 0)	
		ft_errors_handle(10);
	if (execve(data->cmd2.path, data->cmd2.cmd, data->env) < 0)
		ft_errors_handle(11);
}

// int	ft_fork_in(t_data *data, int *pipe_fd)
// {

// 	if (data->cmd1.pid == 0)
// 	{
// 	 Close(pipe_fd[])
// 	}
// 	return(SUCCESS);
// }

// int	ft_fork_out(t_data *data, int *pipe_fd)
// {
// 	int	status;
	
// 	waitpid(data->cmd1.pid, &status);
// 	data->cmd2.pid = fork();
// 	if (data->cmd2.pid == 0)
// 	{
	
// 	}
// 	return(SUCCESS);
// }



//////////////////////////////////////////////////////////////////////////////////////



// execve(char *chemin, char **args_pour_executable, char **env) ????

