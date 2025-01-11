/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/11 18:20:30 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int main(int ac, char **av, char **envp)
{
	t_data	data;
	
	if (ac == 5)
	{
		ft_initialisation_struct(&data, av, envp);
		//if(ft_parsing_handle())
		//ft_pipex();
	}
	else
		write(1, "Nombre d'arguments invalide", 27);
	return (0);
}