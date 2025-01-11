/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:59 by pbret             #+#    #+#             */
/*   Updated: 2025/01/11 18:02:02 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <errno.h>
# include <stdlib.h>

# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

typedef struct s_cmd
{
	char	*path;
	char	**cmd;
}				t_cmd;

typedef struct s_data
{
    char    **env;
    char    *file1;
    char    *file2;
    t_cmd    *cmd1;
    t_cmd    *cmd2;
}           t_data;

/// initialisation struct ///
void	ft_initialisation_struct(t_data *data, char **av, char **env);

char	**ft_split(char *str);

#endif