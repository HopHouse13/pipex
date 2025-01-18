/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/18 16:43:48 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

// getpid() -> recupere le pid sur processus ou nous sommes.

// void	ft_start_pipex(t_data *data)
// {
// 	int pipe_fd[2];
// 	int	status;
	
// 	if (pipe(pipe_fd) == -1)
// 	{
// 		ft_errors_handle(4);
// 		return;
// 	}
// 	if (ft_fork_in(data, pipe_fd))
// 		ft_fork_out(data, pipe_fd);
// 	waitpid(data->cmd1.pid, &status);
// 	waitpid(data->cmd2.pid, &status);
// }

// int	ft_fork_in(t_data *data, int *pipe_fd)
// {
// 	data->cmd1.pid = fork();
// 	if (data->cmd1.pid < 0)
// 	{
// 		ft_errors_handle(5);
// 		return (FAILURE);
// 	}
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


/// SI '/' --> chemin absolu, tester directement avec access
	/// SI valide avec access(X_OK) --> stocker dans path
	/// SI renvoie -1 --> command not found

/// SINON --> Recuperer la ligne du PATH dans l'env


/* ft_substr(),

int res;

res = access("/usr/bin/ls", X_OK);
if (res == -1)
	return (FAILURE);
else if (res == 0)
	return (SUCCESS);


char *path = "PATH=/usr/bin:/usr/sbin";

new_str = ft_substr(str, 5, ft_strlen(path));


char **tab = [[/usr/bin][/usr/sbin][/etc/lol][/etc/tyu]]

BINARY = cat

access(/usr/bincat, X_OK);
access(/usr/sbincat, X_OK);
handle -> manage_ */
