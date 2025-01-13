/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pasing_handle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:31:15 by pbret             #+#    #+#             */
/*   Updated: 2025/01/13 14:06:55 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	ft_parsing_handle(t_data *data)
{
	int	code_error;
	
	code_error = -1;
	if (!ft_is_it_directory(data))
		code_error = 1;
	if (!ft_is_it_openable(data))
		code_error = 2;
	if (!ft_is_it_empty(data))
		code_error = 3;
	if (code_error != -1)
	{
		ft_errors_handle(code_error);
		return (FAILURE);
	}
	return (SUCCESS);
}


int ft_is_it_directory(t_data *data)
{
	int	fd_infile;
	
	fd_infile = 0;
	fd_infile = open(data->infile, __O_DIRECTORY);
	if (fd_infile != -1)
	{
		close(fd_infile);
		return (FAILURE);
	}
	return (SUCCESS);
}

int ft_is_it_openable(t_data *data)
{
	int	fd_infile;
	
	fd_infile = 0;
	fd_infile = open(data->infile, O_RDONLY);
	if (fd_infile == -1)
		return (FAILURE);
	close(fd_infile);
	return (SUCCESS);
}

int ft_is_it_empty(t_data *data)
{
	int		fd_infile;
	char	buffer[1];

	fd_infile = 0;
	fd_infile = open(data->infile, O_RDONLY);
	if (read(fd_infile, buffer, 1) == 0)
	{
		close(fd_infile);
		return (FAILURE);
	}
	close(fd_infile);
	return (SUCCESS);
}