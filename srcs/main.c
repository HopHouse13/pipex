/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/14 16:52:11 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* int	ft_pipex(t_data *data)
{
	int	pipefd[2];

	if (pipe(pipefd) < 0)
	{
		perror("Erreur avec pipe");
		return (1);
	}
} */

int main(int ac, char **av, char **env)
{
	t_data	data;
	
	if (ac == 5)
	{
		if (ft_init_files(&data, av) || ft_init_cmds(&data, av, env))
			ft_start_pipex(&data);
		ft_free(&data);
	}
	else
		ft_errors_handle(0);
	return (0);
}

/// SI '/' --> chemin absolu, tester directement avec access
	/// SI valide avec access(X_OK) --> stocker dans path
	/// SI renvoie -1 --> command not found

/// SINON --> Recuperer la ligne du PATH dans l'env


ft_substr(),

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
handle -> manage_