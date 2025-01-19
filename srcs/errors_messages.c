/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:10:46 by pbret             #+#    #+#             */
/*   Updated: 2025/01/19 20:23:28 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_errors_handle(int code_error)
{
	if (code_error == 0)
		write(2, "Nombre d'arguments invalide\n", 28);
	if (code_error == 1)
		perror("Erreur d'initialisation commande ");
	if (code_error == 2)
		write(2, "Erreur de recupération de la variable PATH.\n", 44);
	if (code_error == 3)
		perror("Erreur d'initialisation du path ");
	if (code_error == 4)
		perror("Erreur d'accès à la commande ");
	if (code_error == 5)
		write(2,"Fichier d'entrée est un repertoire.\n", 36);
	if (code_error == 6)
		perror("Erreur d'accès au fichier d'entrée  ");
}