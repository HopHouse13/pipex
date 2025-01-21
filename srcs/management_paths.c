/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   management_paths.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 16:38:44 by ubuntu            #+#    #+#             */
/*   Updated: 2025/01/21 14:55:34 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int ft_paths_manag(t_data *data, char **env)
{
	data->env = env;
	ft_build_paths_tab(data);
	if (!ft_path_cmd(data, 1) && !ft_path_cmd(data, 2))
		return (SUCCESS);
	else
		return (FAILURE);
}
void	ft_build_paths_tab(t_data *data)
{
	char	*only_paths;
	int		i;
	int		j;
	
	i = -1;
	while (data->env[++i])
		if(!ft_strncmp(data->env[i], "PATH=", 5)) 
		{
			j = 0;
			while (data->env[i][j] != '=')
				j++; // j = 4 alors que "PATH=" = 5
			only_paths = ft_substr(data->env[i], (j + 1), (ft_strlen(data->env[i])));
			if (!only_paths)
				return ;
			data->paths_tab = ft_split(only_paths, ':');
			free (only_paths);
			return ;
		}
}

int	ft_path_cmd(t_data *data, int flag)
{
	if(data->cmd1.cmd[0][0] == '/') // check si la cmd est un chemin absolu.
	{
		if(ft_get_absolute_path(data, flag)) // si la commande est accessible -> on sort du if et on passe a la cmd2. Si c'est pas accessible avec ce chemin absolu -> on tente avec les chemins du PATH.  
		{ft_printf("value pointeur paths_tab: %p\n", data->paths_tab);
			if (data->paths_tab != NULL) // Recuperation de la variable "PATH" en env. si Pas possible -> FAILURE
			{
				if(!ft_get_full_cmd(data, flag)) // fabrication de la commande complete valide avec le chemin absdolu.
					return (SUCCESS);
				return (ft_errors_handle(3), FAILURE);
			}
			return (ft_errors_handle(2), FAILURE); // fin du programme si fail
		}
	}
	else
	{
		if (data->paths_tab != NULL)
		{
			if (!ft_get_full_cmd(data, flag)) // 1 -> flag pour savoir si on traitre de la premiere ou 2eme cmd.
				return (SUCCESS);
			return (ft_errors_handle(3), FAILURE);
		}
		return (ft_errors_handle(2), FAILURE);
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
	while (data->paths_tab[++i])
		{
			path_with_slash = ft_strjoin(data->paths_tab[i], "/");
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
