/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/21 16:54:25 by ubuntu           ###   ########.fr       */
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
		ft_first_cmd(data, pipe_fd);
	data->cmd2.pid = fork();
	if (data->cmd2.pid == -1)
		return (ft_errors_handle(9));
	if (data->cmd2.pid == 0)
		ft_second_cmd(data, pipe_fd);
	close(pipe_fd[0]);
	close(pipe_fd[1]);
	waitpid(data->cmd1.pid, NULL, 0);
	
	waitpid(data->cmd2.pid, NULL, 0);
	printf("pid1 : %d\n", data->cmd1.pid);
	printf("pid2 : %d\n", data->cmd2.pid);

}
void	ft_first_cmd(t_data *data, int *pipe_fd)
{
	if (dup2(data->fd_infile, 0) < 0)
		ft_errors_handle(10);
	close (data->fd_infile);
	if (dup2(pipe_fd[1], 1) < 0)
		ft_errors_handle(10);
	close(pipe_fd[1]);
	close(pipe_fd[0]);
	if (execve(data->cmd1.path, data->cmd1.cmd, data->env) < 0)
		ft_errors_handle(11);
}

void	ft_second_cmd(t_data *data, int *pipe_fd)
{
	if (dup2(pipe_fd[0], 0) < 0)
		ft_errors_handle(10);
	close(pipe_fd[0]);
	if (dup2(data->fd_outfile, 1) < 0)	
		ft_errors_handle(10);
	close(data->fd_outfile);
	close(pipe_fd[1]);
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

