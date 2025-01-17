/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/17 19:30:46 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


int main(int ac, char **av/* , char **env */)
{
	t_data	data;
	
	if (ac == 5)
	{
		if (!ft_init_cmds(&data, av) &&
			/* !ft_init_paths(&data, env) && */
			!ft_init_files(&data, av))
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
 
