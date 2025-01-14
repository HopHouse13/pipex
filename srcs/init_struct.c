/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/14 16:52:11 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

// open(file, O_CREAT | O_RDWR | O_TRUNC, 0644);


int	ft_init_files(t_data *data, char **av)
{
	data->infile = av[1];
	data->outfile = av[4];
	if (ft_is_directory(data))
		return (FAILURE);
	else if (ft_is_openable(data))
		return (FAILURE);
	return (SUCCESS);
}
int	ft_init_cmds(t_data *data, char **av, char **env)
{
	data->env = env;
	data->cmd1.cmd = ft_split(av[2], ' ');
	if (!data->cmd1.cmd)
		return (ft_errors_handle(3), FAILURE);
	data->cmd2.cmd = ft_split(av[3], ' ');
	if (!data->cmd1.cmd) 
		return (ft_errors_handle(3), FAILURE);
	ft_build_path(data, env)
	return (SUCCESS);
}

int ft_is_directory(t_data *data)
{
	int	fd_infile;
	int fd_outfile;

	fd_infile = open(data->infile, __O_DIRECTORY);
	fd_outfile = open(data->outfile, __O_DIRECTORY);
	if (fd_infile != -1)
	{
		close(fd_infile);
		ft_errors_handle(1);
		return (FAILURE);
	}
	if (fd_outfile != -1)
	{
		close(fd_outfile);
		ft_errors_handle(1);
		return (FAILURE);
	}
	return (SUCCESS);
}

int ft_is_openable(t_data *data)
{
	data->fd_infile = open(data->infile, O_RDONLY);
	if (data->fd_infile == -1)
	{
		ft_errors_handle(2);
		return (FAILURE);
	}
	data->fd_outfile = open(data->outfile, O_RDONLY);
	if (data->fd_outfile == -1)
	{
		ft_errors_handle(2);
		return (FAILURE);
	}
	return (SUCCESS);
}
