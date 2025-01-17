/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_errors_handle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:10:46 by pbret             #+#    #+#             */
/*   Updated: 2025/01/17 14:27:27 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_errors_handle(int code_error)
{
	if (code_error == 0)
		write(2, "Nombre d'arguments invalide\n", 28);
	if (code_error == 1)
		write(2, "Le fichier d'entrée est une repertoire.\n", 40);
	if (code_error == 2)
		perror("Fichier non ouvrable ");	
	if (code_error == 3)
		write(2, "PATH inexistant dans les variables d'environnement\n", 51);
	if (code_error == 4)
		perror("Erreur d'initialisation de commande ");
	if (code_error == 5)
		perror("Erreur d'acces a la commande ");

}	