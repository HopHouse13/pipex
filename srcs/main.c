/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/12 12:07:31 by ubuntu           ###   ########.fr       */
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
		ft_free(&data);
	}
	else
		write(1, "Nombre d'arguments invalide", 27);
	return (0);
}