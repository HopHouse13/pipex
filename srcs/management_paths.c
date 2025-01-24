/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:44 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/23 13:43:25 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	ft_paths_manag(t_data *data, char **env)
{
	data->env = env;
	ft_build_paths_tab(data);
	if (!ft_path_cmd(data, 1) && !ft_path_cmd(data, 2))
		return (SUCCESS);
	else
		return (FAILURE);
}

// j = 4 alors que "PATH=" = 5 -> toujours l'histoire d'indexe et le nombre
// de caractere.				
void	ft_build_paths_tab(t_data *data)
{
	char	*only_paths;
	int		i;
	int		j;

	i = -1;
	while (data->env[++i])
	{
		if (!ft_strncmp(data->env[i], "PATH=", 5))
		{
			j = 0;
			while (data->env[i][j] != '=')
				j++;
			only_paths = ft_substr(data->env[i], j +1, ft_strlen(data->env[i]));
			if (!only_paths)
				return ;
			data->paths_tab = ft_split(only_paths, ':');
			free (only_paths);
			return ;
		}
	}
}

int	ft_path_cmd(t_data *data, int flag)
{
	if (data->cmd1.cmd[0][0] == '/')
	{
		if (ft_check_absolute_path(data, flag) == SUCCESS)
			return (SUCCESS);
		return (ft_errors_handle(3), FAILURE);
	}
	else
	{
		if (data->paths_tab != NULL)
		{
			if (!ft_build_path(data, flag))
				return (SUCCESS);
			return (ft_errors_handle(3), FAILURE);
		}
		return (ft_errors_handle(2), FAILURE);
	}
	return (SUCCESS);
}

int	ft_check_absolute_path(t_data *data, int flag)
{
	t_cmd	*current_cmd;

	if (flag == 1)
		current_cmd = &(data->cmd1);
	else
		current_cmd = &(data->cmd2);
	if (current_cmd->cmd[0][0] == '/')
	{
		if (access(current_cmd->cmd[0], F_OK | X_OK) < 0)
			return (FAILURE);
		else
		{
			current_cmd->path = ft_strdup(current_cmd->cmd[0]);
			if (!current_cmd->path)
				return (ft_errors_handle(3), FAILURE);
		}
	}
	return (SUCCESS);
}

int	ft_build_path(t_data *data, int flag)
{
	char	*path_with_slash;
	char	*full_path;
	int		i;
	t_cmd	*current_cmd;

	if (flag == 1)
		current_cmd = &(data->cmd1);
	else
		current_cmd = &(data->cmd2);
	i = -1;
	while (data->paths_tab[++i])
	{
		path_with_slash = ft_strjoin(data->paths_tab[i], "/");
		if (!path_with_slash)
			break ;
		full_path = ft_strjoin(path_with_slash, current_cmd->cmd[0]);
		free(path_with_slash);
		if (!full_path)
			break ;
		if (access(full_path, F_OK | X_OK) < 0)
			free(full_path);
		else
			return (current_cmd->path = full_path, SUCCESS);
	}
	return (FAILURE);
}
