/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ubuntu <ubuntu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:31 by pbret             #+#    #+#             */
/*   Updated: 2025/01/21 17:44:39 by ubuntu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"


// valgrind --leak-check=full --track-origins=yes ./pipex infile "ls" "grep a" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "cat -e" "grep hello" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "ls -l" "wc -l" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "grep -i error" "sort" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "awk '{print \$1}'" "uniq" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "cut -d' ' -f2" "sort -r" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "tr a-z A-Z" "rev" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "head -n 5" "tail -n 2" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "sort" "uniq -c" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "echo 'test'" "wc -c" outfile
// valgrind --leak-check=full --track-origins=yes ./pipex infile "grep -v '^#'" "wc -l" outfile

void FT_ASUPP_PINTF(t_data *data)
{
	int	c = 1;
	int	i = -1;
	printf("infile : %s\noutfile : %s\ncmd1_path : %s\ncmd2_path : %s\n", data->infile, data->outfile, data->cmd1.path, data->cmd2.path);//ft_start_pipex(&data);
	while (data->paths_tab[++i])
		printf("path_tab_N%d -> %s\n", c, data->paths_tab[i]), c++;
	i = -1;
	c = 1;
	while (data->cmd1.cmd[++i])
		printf("cmd1_N%d -> %s\n", c, data->cmd1.cmd[i]), c++;
	i = -1;
	c = 1;
	while (data->cmd2.cmd[++i])
		printf("cmd2_N%d -> %s\n", c, data->cmd2.cmd[i]), c++;
}

int main(int ac, char **av, char **env)
{
	t_data	data;
	
	if (ac == 5)
	{
		ft_init_values_struct(&data);
		if (!ft_cmds_manag(&data, av) &&
			!ft_paths_manag(&data, env) &&
			!ft_files_manag(&data, av))
		{
			FT_ASUPP_PINTF(&data);
			ft_exec_pipex(&data);
		}
		else
			printf("\nLOOSE\n");
		ft_free(&data);
		ft_close_fd(&data);
	}
	else
		ft_errors_handle(0);
	return (0);
}
 
