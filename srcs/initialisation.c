/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 16:03:40 by pbret             #+#    #+#             */
/*   Updated: 2025/01/15 18:56:58 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

int	ft_init_files(t_data *data, char **av)
{
	data->infile = av[1];
	data->outfile = av[4];
	if (!ft_is_directory(data))
		return (FAILURE);
	if (!ft_is_openable(data))
		return (FAILURE);
	return (SUCCESS);
}
int	ft_init_cmds(t_data *data, char **av, char **env)
{
	data->env = env;
	if(!data->env) // modifier cette condition -> check si il y a "PATH=" dans env
		return (ft_errors_handle(3), FAILURE);
	data->cmd1.cmd = ft_split(av[2], ' ');
	data->cmd2.cmd = ft_split(av[3], ' ');
	if (!data->cmd1.cmd | !data->cmd1.cmd)
		return (ft_errors_handle(4), FAILURE);
	/* if (!ft_build_path(data, env))
		return (FAILURE); */
	return (SUCCESS);
}

int ft_is_directory(t_data *data)
{
	data->fd_infile = open(data->infile, __O_DIRECTORY);
	data->fd_outfile = open(data->outfile, __O_DIRECTORY);
	if (data->fd_infile != -1 || data->fd_outfile != -1) // si c'est un dossier
		return (ft_errors_handle(1), FAILURE);
	return (SUCCESS);
}

int ft_is_openable(t_data *data)
{
	data->fd_infile = open(data->infile, O_RDONLY);
	data->fd_outfile = open(data->outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
	if (data->fd_infile == -1 || data->fd_outfile == -1) // si non fichier 
		return (ft_errors_handle(2), FAILURE);
	return (SUCCESS);
}

/* int	ft_build_path(t_data *data, char **env)
{
	if (data->cmd1.cmd[0][0] == '/')
		if(access(data->cmd1.cmd[0], F_OK | X_OK) < 0)
			return (ft_errors_handle(5), FAILURE);
		else
			data->cmd1.path = data->cmd1.cmd;
	if (data->cmd2.cmd[0][0] == '/')
		if(access(data->cmd2.cmd[0], F_OK | X_OK) < 0)
			return (ft_errors_handle(5), FAILURE);
	return (SUCCESS);
} */
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
