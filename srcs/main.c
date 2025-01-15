/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/15 17:33:46 by pbret            ###   ########.fr       */
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
			printf("WIN\n");//ft_start_pipex(&data);
		else
			printf("LOOSE\n");
		ft_free(&data);
		ft_close_fd(&data);
	}
	else
		ft_errors_handle(0);
	return (0);
}
 
