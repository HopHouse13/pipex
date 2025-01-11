/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/11 18:21:47 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_initialisation_struct(t_data *data, char **av, char **envp)
{
	data->env = envp;
	data->cmd1->cmd = ft_split(av[2]);
	//data->cmd1->path = NULL;
	data->cmd2->cmd = ft_split(av[3]);
	//data->cmd2->path = NULL;
	//data->file1 = av[1];
	//data->file2 = av[4];
	// printf("%s\n", data->cmd1->cmd[0]);
	// printf("%s\n", data->cmd1->cmd[1]);
	free (data->cmd1->cmd);
	free (data->cmd2->cmd);
}
