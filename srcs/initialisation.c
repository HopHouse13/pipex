/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/17 21:02:11 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	ft_init_cmds(t_data *data, char **av)
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

int ft_init_paths(t_data *data, char **env)
{
	data->env = env;
	if (ft_find_env_path(data))
		return (FAILURE);
	if (data->cmd1.cmd[0][0] == '/')
	{
		if(access(data->cmd1.cmd[0], F_OK | X_OK) < 0) // F_ok -> si la commande existe | X_ok -> si il est executable
			return (ft_errors_handle(5), FAILURE);
		else
			data->cmd1.path = data->cmd1.cmd[0];
	}
	if (data->cmd2.cmd[0][0] == '/')
	{
		if(access(data->cmd2.cmd[0], F_OK | X_OK) < 0)
			return (ft_errors_handle(5), FAILURE);
		else
			data->cmd2.path = data->cmd2.cmd[0];
	}
	return (SUCCESS);
}

int	ft_init_files(t_data *data, char **av)
{
	data->infile = av[1];
	data->outfile = av[4];
	if (ft_is_directory(data))
		return (FAILURE);
	if (ft_is_openable(data))
		return (FAILURE);
	return (SUCCESS);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// FILES //

int ft_is_directory(t_data *data) // si c'est un dossier
{
	data->fd_infile = open(data->infile, __O_DIRECTORY);
	 data->fd_outfile = open(data->outfile, __O_DIRECTORY); // JE CROIS QUE CELA N'EST PAS UTILSE -> si il ya un repertoire du meme nom en s'en fiche non???????
	if (data->fd_infile != -1 || data->fd_outfile != -1)
		return (ft_errors_handle(1), FAILURE);
	return (SUCCESS);
}

int ft_is_openable(t_data *data)
{
	data->fd_infile = open(data->infile, O_RDONLY);
	if (data->fd_infile == -1)
		return (ft_errors_handle(2), FAILURE);
	data->fd_outfile = open(data->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_outfile == -1) // si non fichier -> creation /////  A FAIRE A LA FIN SI PIPEX A FONCTIONNE <<<<
		return (ft_errors_handle(2), FAILURE);
	return (SUCCESS);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////
// PATHS //

int	ft_find_env_path(t_data *data)
{
	int i;

	i = -1;
	while (data->env[++i])
		if(ft_strncmp(data->env[i], "PATH=", 5))
			return(SUCCESS);
	ft_errors_handle(3);
	return (FAILURE);
}
/////////////////////////////////////////////////////////////////////////////////////////////////////
// CMDS //
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

////////////////////////////////////////////////////////////////////////////////////

// execve(char *chemin, char **args_pour_executable, char **env) ????


/// SI '/' --> chemin absolu, tester directement avec access
	/// SI valide avec access(X_OK) --> stocker dans path
	/// SI renvoie -1 --> command not found

/// SINON --> Recuperer la ligne du PATH dans l'env


/* ft_substr(),

int res;

res = access("/usr/bin/ls", X_OK);
if (res == -1)
	return (FAILURE);
else if (res == 0)
	return (SUCCESS);


char *path = "PATH=/usr/bin:/usr/sbin";

new_str = ft_substr(str, 5, ft_strlen(path));


char **tab = [[/usr/bin][/usr/sbin][/etc/lol][/etc/tyu]]

BINARY = cat

access(/usr/bincat, X_OK);
access(/usr/sbincat, X_OK);
handle -> manage_ */
