/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:23:21 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/31 00:43:54 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# define READ_END 0
# define WRITE_END 1
# define INFILE 0
# define OUTFILE 1

typedef struct s_struct
{
	int		infile_fd;
	int		outfile_fd;
	char	path[100];
	char	**arg;
	char	**envp;
}		t_cmd;

int		pipex(t_cmd *commands);
void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
void	ft_check_infile(char *file_path);
void	ft_check_outfile(char *file_path);
void	ft_get_cmd_path(t_cmd *commands);
void	ft_fill_cmd(t_cmd *commands, int argc, char *argv[], char **envp);
void	ft_free_command(t_cmd *commands);
void	error(char *error_string);

#endif
