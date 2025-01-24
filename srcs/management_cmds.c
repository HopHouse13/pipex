/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_cmds.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:27 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/22 13:46:56 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_cmds_manag(t_data *data, char **av)
{
	if (!ft_if_only_space(av[2]))
	{
		if (ft_cmd_space(data, 1))
			return (ft_errors_handle(1), FAILURE);
	}
	else
	{
		data->cmd1.cmd = ft_split(av[2], ' ');
		if (!data->cmd1.cmd)
			return (ft_errors_handle(1), FAILURE);
	}	
	if (!ft_if_only_space(av[3]))
	{
		if (ft_cmd_space(data, 2))
			return (ft_errors_handle(1), FAILURE);
	}
	else
	{
		data->cmd2.cmd = ft_split(av[3], ' ');
		if (!data->cmd2.cmd)
			return (ft_errors_handle(1), FAILURE);
	}
	return (SUCCESS);
}

int	ft_if_only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] != ' ')
			return (FAILURE);
	return (SUCCESS);
}

int	ft_cmd_space(t_data *data, int flag)
{
	char	**tmp;

	tmp = malloc(2 * sizeof(char *));
	if (!tmp)
	{
		tmp = NULL;
		return (FAILURE);
	}
	tmp[1] = NULL;
	tmp[0] = malloc(2 * sizeof(char));
	if (!tmp[0])
	{
		tmp[0][0] = '\0';
		return (FAILURE);
	}
	tmp[0][0] = ' ';
	tmp[0][1] = '\0';
	if (flag == 1)
		data->cmd1.cmd = tmp;
	else
		data->cmd2.cmd = tmp;
	return (SUCCESS);
}
