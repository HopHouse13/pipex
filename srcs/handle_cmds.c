/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:27 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/18 20:03:26 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	ft_cmds_manag(t_data *data, char **av)
{
	if (!ft_if_only_space(av[2]))
	{
		if (ft_cmd_space(data, 1))
			return (FAILURE);
	}
	else
	{
		data->cmd1.cmd = ft_split(av[2], ' ');
		if (!data->cmd1.cmd)
			return (FAILURE);
	}	
	if (!ft_if_only_space(av[3]))
	{
		if (ft_cmd_space(data, 2))
			return (FAILURE);	
	}
	else
	{
		data->cmd2.cmd = ft_split(av[3], ' ');
		if (!data->cmd1.cmd)
			return (FAILURE);
	}
	return (SUCCESS);
}
int	ft_if_only_space(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if(str[i] != ' ')
			return (FAILURE);
	return (SUCCESS);
}
int ft_cmd_space(t_data *data, int flag)
{
	char **tmp;

	tmp = malloc(2 * sizeof(char*));
	if (!tmp)
	{
		tmp = NULL;
		ft_errors_handle(4);
		return (FAILURE);
	}
	tmp[1] = NULL;
	tmp[0] = malloc(2 * sizeof(char));
	if (!tmp[0])
	{
		tmp[0][0] = '\0';
		ft_errors_handle(4);
		return (FAILURE);
	}
	tmp[0][0] = ' ';
	tmp[0][1] = '\0';
	if(flag == 1)
		data->cmd1.cmd = tmp;
	else
		data->cmd2.cmd = tmp;
	return (SUCCESS);
}

