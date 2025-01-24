/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation_struct.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:42:42 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/22 13:47:15 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// les variables de type t_pid ne sont pas initialisees. Selon le systemes,
// le type pid peut prendre differents types. Ce type est utilise pour
// la portabilite de ce programme dans differents systemes. 
void	ft_init_values_struct(t_data *data)
{
	data->env = NULL;
	data->paths_tab = NULL;
	data->infile = NULL;
	data->outfile = NULL;
	data->fd_infile = -1;
	data->fd_outfile = -1;
	data->cmd1.path = NULL;
	data->cmd1.cmd = NULL;
	data->cmd2.path = NULL;
	data->cmd2.cmd = NULL;
}
