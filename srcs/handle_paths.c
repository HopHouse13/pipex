/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:44 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/18 20:09:36 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int ft_paths_manag(t_data *data, char **env)
{
	data->env = env;
/* 	int i = -1; // POUR IMPRIMER ENV
	while (data->env[++i])
		ft_printf("env >>> %s\n", data->env[i]);
	ft_printf ("\n////////////////////////////////////\n"); */
	if (ft_find_paths_line(data))
		return (FAILURE);
	if (data->cmd1.cmd[0][0] == '/')
	{
		if(access(data->cmd1.cmd[0], F_OK | X_OK) < 0) // F_ok -> si la commande existe | X_ok -> si il est executable
			return (ft_errors_handle(5), FAILURE);
		else
			data->cmd1.path = data->cmd1.cmd[0];
	}
	/* else
		ft_build_cmd_path(data); */
	if (data->cmd2.cmd[0][0] == '/')
	{
		if(access(data->cmd2.cmd[0], F_OK | X_OK) < 0)
			return (ft_errors_handle(5), FAILURE);
		else
			data->cmd2.path = data->cmd2.cmd[0];
	}
/* 	else
		ft_build_cmd_path(data); */
	return (SUCCESS);
}

int	ft_find_paths_line(t_data *data)
{
	int i;

	i = -1;
	while (data->env[++i])
	{
		if(!ft_strncmp(data->env[i], "PATH=", 5))
		{
			if (!ft_build_all_paths(data, data->env[i]))
				return (FAILURE);
			return(SUCCESS);
		}
	}
	ft_errors_handle(3);
	return (FAILURE);
}

int	ft_build_all_paths(t_data *data, char *paths_line)
{
	char *only_paths;
	int	i;
	int	j;
	
	i = 0;
	while (paths_line[i] != '=')
		i++; // i = 4 alors que "PATH=" = 5
	only_paths = malloc((ft_strlen(paths_line) - (i + 1) + 1) * sizeof(char)); // "i + 1" pour avoir le bon nombre de caractere du nom de la variable.
	if (!only_paths)
		return (FAILURE);
	only_paths[ft_strlen(paths_line) - (i + 1)] = '\0';
	j = -1;
	while (paths_line[i])
		only_paths[++j] = paths_line[++i];
	data->all_paths = ft_split(only_paths, ':');
	if (data->all_paths == NULL)
		return(FAILURE);
	free(only_paths);
	ft_printf("paths_value = %s\n", data->all_paths);
	//only_paths = ft_supp_variable_name(paths_line)
	//data->all_paths = ft_split();
	return (SUCCESS);
}

