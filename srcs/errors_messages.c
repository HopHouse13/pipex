/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_messages.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:10:46 by pbret             #+#    #+#             */
/*   Updated: 2025/01/20 20:29:15 by pbret            ###   ########.fr       */
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
		write(2, "Erreur de recupération de la variable d'env. PATH.\n", 51);
	if (code_error == 3)
		perror("Erreur d'initialisation du path ");
	if (code_error == 4)
		perror("Erreur d'accès à la commande ");
	if (code_error == 5)
		write(2,"Le fichier d'entrée est un repertoire.\n", 39);
	if (code_error == 6)
		perror("Erreur d'accès au fichier d'entrée  ");
	if (code_error == 7)
		perror("Erreur d'initialisation du pipe  ");
	if (code_error == 8)
		perror("Erreur lors de la creation du premier processus	enfant ");
	if (code_error == 9)
		perror("Erreur lors de la creation du second processus enfant ");
	if (code_error == 10)
		perror("Erreur de redirection de commande ");
	if (code_error == 11)
		perror("Erreur d'execution de commande ");
}
