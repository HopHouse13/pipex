/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/19 20:55:17 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// commande definitily lost :
// valgrind --leak-check=full --track-origins=yes ./pipex "fichier_test_avec_droits" "ls" "grep a" "outfile.txt"

int main(int ac, char **av, char **env)
{
	t_data	data;
	
	if (ac == 5)
	{
		ft_init_values_struct(&data);
		if (!ft_cmds_manag(&data, av) &&
			!ft_paths_manag(&data, env) &&
			!ft_files_manag(&data, av))
			printf("\nWIN\n");//ft_start_pipex(&data);
		else
			printf("\nLOOSE\n");
		ft_free(&data);
		ft_close_fd(&data);
	}
	else
		ft_errors_handle(0);
	return (0);
}
 
