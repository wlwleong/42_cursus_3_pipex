/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 17:43:36 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/20 17:47:52 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>

char	**ft_split(char const *s, char c);
char	*ft_get_cmd_path(char *cmd, char **envp);
void	pipex(int file1_fd, char *cmd[], int file2_fd, char **envp);

#endif
