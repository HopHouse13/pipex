/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/13 15:18:48 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av, char **envp)
{
	t_data	data;
	
	if (ac == 5)
	{
		ft_initialisation_struct(&data, av, envp);
		if(ft_parsing_handle(&data))
			ft_pipex(&data);
		ft_free(&data);
	}
	else
		ft_errors_handle(0);
	return (0);
}