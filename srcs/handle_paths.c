/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:44 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/19 13:02:04 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int ft_paths_manag(t_data *data, char **env)
{
	data->env = env;

	if (data->cmd1.cmd[0][0] == '/')
	{
		if(access(data->cmd1.cmd[0], F_OK | X_OK) < 0) // F_ok -> si la commande existe | X_ok -> si il est executable
			return (ft_errors_handle(5), FAILURE);
		else
			data->cmd1.path = data->cmd1.cmd[0];
	}
	else
	{
		if (ft_build_paths_tab(data))
			return (FAILURE);
		ft_build_cmd_path(data);
	}
/* 	if (data->cmd2.cmd[0][0] == '/')
	{
		if(access(data->cmd2.cmd[0], F_OK | X_OK) < 0)
			return (ft_errors_handle(5), FAILURE);
		else
			data->cmd2.path = data->cmd2.cmd[0];
	}
 	else
		ft_build_cmd_path(data);
	return (SUCCESS); */
}

int	ft_build_paths_tab(t_data *data)
{
	int i;

	i = -1;
	while (data->env[++i])
	{
		if(!ft_strncmp(data->env[i], "PATH=", 5)) // trouver dans env si il ya la line PATH=
		{
			if (!ft_build_all_paths(data, data->env[i])) // mettre dans data->all_paths chaque path (sans le nom de la variable)
				return (SUCCESS);
			else
				ft_errors_handle(4); // erreur d'initialisation tab_paths
		}
	}
	ft_errors_handle(3);
	return (FAILURE);
}

int	ft_build_all_paths(t_data *data, char *paths_line)
{
	char	*only_paths;
	int		i;
	
	i = 0;
	while (paths_line[i] != '=')
		i++; // i = 4 alors que "PATH=" = 5
	only_paths = ft_substr(paths_line, (i + 1), ft_strlen(paths_line));
	if (!only_paths)
		return (FAILURE);
	data->all_paths = ft_split(only_paths, ':');
	if (!data->all_paths)
		return (FAILURE);
	/* i = -1;
	while (data->all_paths[++i])
		ft_printf("PATH >>> %s\n", data->all_paths[i]); */
	return (SUCCESS);
}

