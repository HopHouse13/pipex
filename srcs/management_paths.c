/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:44 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/19 20:53:00 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int ft_paths_manag(t_data *data, char **env)
{
	data->env = env;
	if (!ft_path_cmd(data, 1) && !ft_path_cmd(data, 2))
		return (SUCCESS);
	else
		return (FAILURE);
}
int	ft_path_cmd(t_data *data, int flag)
{
	if(data->cmd1.cmd[0][0] == '/') // check si la cmd est un chemin absolu.
	{
		if(ft_get_absolute_path(data, flag)) // si la commande est accessible -> on sort du if et on passe a la cmd2. Si c'est pas accessible avec ce chemin absolu -> on tente avec les chemins du PATH.  
		{
			if (!ft_get_paths_tab(data)) // Recuperation de la variable "PATH" en env. si Pas possible -> FAILURE
				if(!ft_get_full_cmd(data, flag)) // fabrication de la commande complete valide avec le chemin absdolu.
					return (SUCCESS);
			return (FAILURE); // fin du programme si fail
		}	
	}
	else
	{
		if (!ft_get_paths_tab(data))
			if (!ft_get_full_cmd(data, 1)) // 1 -> flag pour savoir si on traitre de la premiere ou 2eme cmd.
				return (SUCCESS);
		return (FAILURE);
	}
	return (SUCCESS);
}


int	ft_get_absolute_path(t_data *data, int flag)
{
	t_cmd	*current_cmd;

	if(flag == 1)
		current_cmd = &(data->cmd1);
	else
		current_cmd = &(data->cmd2);

	if (current_cmd->cmd[0][0] == '/')
	{
		if(access(current_cmd->cmd[0], F_OK | X_OK) < 0) // F_ok -> si la commande existe | X_ok -> si il est executable
			return (FAILURE);
		else
			current_cmd->path = current_cmd->cmd[0];
	}
	return (SUCCESS);
}

int	ft_get_paths_tab(t_data *data)
{
	int i;

	i = -1;
	while (data->env[++i])
	{
		if(!ft_strncmp(data->env[i], "PATH=", 5)) // trouver dans env si il ya la line PATH=
		{
			if (!ft_build_all_paths_tab(data, data->env[i])) // mets dans data->all_paths chaque path (sans le nom de la variable)
				return (SUCCESS);
			else
				return (ft_errors_handle(3), FAILURE); // erreur d'initialisation tab_paths
		}
	}
	return (ft_errors_handle(2), FAILURE); // pas trouve "PATH=" dans env
}

int	ft_build_all_paths_tab(t_data *data, char *paths_line)
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
	free (only_paths);
	if (!data->all_paths)
		return (FAILURE);
	return (SUCCESS);
}

int	ft_get_full_cmd(t_data *data, int flag)
{
	char	*path_with_slash;
	char	*full_path;
	int		i;
	t_cmd	*current_cmd;

	if(flag == 1)
		current_cmd = &(data->cmd1);
	else
		current_cmd = &(data->cmd2);
	i = -1;
	while (data->all_paths[++i])
		{
			path_with_slash = ft_strjoin(data->all_paths[i], "/");
			if (!path_with_slash)
				break;
			full_path = ft_strjoin(path_with_slash, current_cmd->cmd[0]);
			free(path_with_slash);	
			if (!full_path)
				break;
			if (access(full_path, F_OK | X_OK) < 0)
				free(full_path);
			else
				return (current_cmd->path = full_path, SUCCESS);
		}
	return (ft_errors_handle(4), FAILURE);
}
