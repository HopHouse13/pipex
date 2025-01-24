/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:10:46 by pbret             #+#    #+#             */
/*   Updated: 2025/01/23 13:14:31 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_errors_handle(int code_error)
{
	if (code_error == 0)
		write(2, RED"Nombre d'arguments invalide.\n"RESET, 36);
	if (code_error == 1)
		perror(RED"Erreur d'initialisation commande "RESET);
	if (code_error == 2)
		write(2, RED"Erreur de recupération de la variable PATH.\n"RESET, 50);
	if (code_error == 3)
		perror(RED"Erreur d'accès à la commande "RESET);
	if (code_error == 4)
		write(2, RED"Le fichier d'entrée est un repertoire.\n"RESET, 46);
	if (code_error == 5)
		perror(RED"Erreur d'accès au fichier "RESET);
	if (code_error == 6)
		perror(RED"Erreur d'initialisation du pipe "RESET);
	if (code_error == 7)
		perror(RED"Erreur de la creation du premier processus enfant "RESET);
	if (code_error == 8)
		perror(RED"Erreur de la creation du second processus enfant "RESET);
	if (code_error == 9)
		perror(RED"Erreur de redirection de commande "RESET);
	if (code_error == 10)
		perror(RED"Erreur d'execution de commande "RESET);
}
