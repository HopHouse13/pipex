/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages_errors_handle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 11:10:46 by pbret             #+#    #+#             */
/*   Updated: 2025/01/13 15:15:05 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/pipex.h"

void	ft_errors_handle(int code_error)
{
	if (code_error == 0)
		write(2, "Nombre d'arguments invalide\n", 28);
	if (code_error == 1)
		perror("Argument d'entree n'est pas un fichier ");
	if (code_error == 2)
		perror("Fichier non ouvrable ");
	if (code_error == 3)
		write(2, "Fichier vide\n", 13);
}