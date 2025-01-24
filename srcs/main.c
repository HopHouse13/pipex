/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/22 17:52:18 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

// ./pipex infile "cat" "grep txt" outfile				-> les lignes "txt"
// ./pipex infile "cat" "wc -l" outfile					-> 10 (lignes)
// ./pipex infile "grep bonjour" "grep monde" outfile	-> affiche "bonjour ..."
// ./pipex infile "cat" "tr 'a-z' 'A-Z'" outfile		-> FULL MAJ
// ./pipex infile "cat" "head -n 5" outfile				-> Affiche les 5 first

//Fonction pour imprimer les variables de la strcuture:
/* void FT_ASUPP_PINTF(t_data *data)
{
	int	c = 1;
	int	i = -1;
	ft_printf("infile : %s\noutfile : %s\ncmd1_path : %s\ncmd2_path : %s\n",
	 data->infile, data->outfile, data->cmd1.path, data->cmd2.path);
	while (data->paths_tab[++i])
		ft_printf("path_tab_N%d -> %s\n", c, data->paths_tab[i]), c++;
	i = -1;
	c = 1;
	while (data->cmd1.cmd[++i])
		ft_printf("cmd1_N%d -> %s\n", c, data->cmd1.cmd[i]), c++;
	i = -1;
	c = 1;
	while (data->cmd2.cmd[++i])
		ft_printf("cmd2_N%d -> %s\n", c, data->cmd2.cmd[i]), c++;
} */

int	main(int ac, char **av, char **env)
{
	t_data	data;

	if (ac == 5)
	{
		ft_init_values_struct(&data);
		if (!ft_cmds_manag(&data, av)
			&& !ft_paths_manag(&data, env)
			&& !ft_files_manag(&data, av))
			ft_exec_pipex(&data);
		ft_master_free_and_close(&data);
	}
	else
		ft_errors_handle(0);
	return (0);
}
