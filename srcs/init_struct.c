/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/12 11:57:41 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_initialisation_struct(t_data *data, char **av, char **envp)
{
	data->env = envp;
	data->cmd1 = malloc(sizeof(t_cmd));
	data->cmd1->cmd = ft_split(av[2], ' ');
	data->cmd1->path = NULL;
	data->cmd2 = malloc(sizeof(t_cmd));
	data->cmd2->cmd = ft_split(av[3], ' ');
	data->cmd2->path = NULL;
	data->file1 = av[1];
	data->file2 = av[4];
	// printf(">>>%s\n", data->file1);
	ft_free(data);
}
