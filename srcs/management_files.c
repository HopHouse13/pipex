/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_files.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:39:11 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/22 17:38:33 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_files_manag(t_data *data, char **av)
{
	data->infile = av[1];
	data->outfile = av[4];
	if (ft_is_directory(data))
		return (ft_errors_handle(4), FAILURE);
	if (ft_is_openable(data))
		return (ft_errors_handle(5), FAILURE);
	return (SUCCESS);
}

// Si les fichiers sont des repertoires sinon-> erreur
int	ft_is_directory(t_data *data)
{
	data->fd_infile = open(data->infile, __O_DIRECTORY);
	data->fd_outfile = open(data->outfile, __O_DIRECTORY);
	if (data->fd_infile != -1 || data->fd_outfile != -1)
		return (FAILURE);
	return (SUCCESS);
}

// check si les fichiers sont ouvrables sinon-> erreur
// si le outfile est inexistant -> creation
int	ft_is_openable(t_data *data)
{
	data->fd_infile = open(data->infile, O_RDONLY);
	if (data->fd_infile == -1)
		return (FAILURE);
	data->fd_outfile = open(data->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_outfile == -1)
		return (FAILURE);
	return (SUCCESS);
}
