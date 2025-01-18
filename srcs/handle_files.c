/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:39:11 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/18 17:40:20 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	ft_files_manag(t_data *data, char **av)
{
	data->infile = av[1];
	data->outfile = av[4];
	if (ft_is_directory(data))
		return (FAILURE);
	if (ft_is_openable(data))
		return (FAILURE);
	return (SUCCESS);
}

int ft_is_directory(t_data *data) // si c'est un dossier
{
	data->fd_infile = open(data->infile, __O_DIRECTORY);
	data->fd_outfile = open(data->outfile, __O_DIRECTORY); // JE CROIS QUE CELA N'EST PAS UTILSE -> si il ya un repertoire du meme nom en s'en fiche non???????
	if (data->fd_infile != -1 || data->fd_outfile != -1)
		return (ft_errors_handle(1), FAILURE);
	return (SUCCESS);
}

int ft_is_openable(t_data *data)
{
	data->fd_infile = open(data->infile, O_RDONLY);
	if (data->fd_infile == -1)
		return (ft_errors_handle(2), FAILURE);
	data->fd_outfile = open(data->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_outfile == -1) // si non fichier -> creation /////  A FAIRE A LA FIN SI PIPEX A FONCTIONNE <<<<
		return (ft_errors_handle(2), FAILURE);
	return (SUCCESS);
}
