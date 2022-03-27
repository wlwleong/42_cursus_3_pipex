/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:23:21 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/23 16:24:12 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# define N_COMMAND argc - 3

typedef struct  s_struct
{
    char    path[100];
    char    **arg;
    char    **envp;
}               t_cmd;

char	**ft_split(char const *s, char c);
void	ft_get_cmd_path(t_cmd *commands);
void	ft_fill_cmd(t_cmd *commands, int argc, char *argv[], char **envp);
int     ft_get_infile(char *file_path);
int	    ft_get_outfile(char *file_path);

#endif