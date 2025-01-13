/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbret <pbret@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 15:11:59 by pbret             #+#    #+#             */
/*   Updated: 2025/01/13 18:47:17 by pbret            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>	// write; pipe; fork
# include <stdio.h>		// perror
# include <errno.h>
# include <stdlib.h>	// malloc
# include <fcntl.h>		// open


# define RESET "\033[0m"
# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define WHITE "\033[37m"

# define FAILURE 0
# define SUCCESS 1

typedef struct s_cmd
{
	char	*path;
	char	**cmd;
	pid_t	pid;
}			t_cmd;

typedef struct s_data
{
    char    **env;
    char    *infile;
    char    *outfile;
    t_cmd    cmd1;
    t_cmd    cmd2;
}           t_data;

/// initialisation struct ///
void	ft_initialisation_struct(t_data *data, char **av, char **env);
char	**ft_split(char *str, char separator);

/// pipex ///
void	ft_start_pipex(t_data data);

/// tools ///
void	ft_free(t_data *data);

/// error_handle ///
int		ft_parsing_handle(t_data *data);
int		ft_is_it_a_directory(t_data *data);
int		ft_is_it_openable(t_data *data);
int		ft_is_it_empty(t_data *data);

/// error_message ///
void	ft_errors_handle(int code_error);
#endif