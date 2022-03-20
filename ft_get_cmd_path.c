/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 12:00:30 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/20 17:21:35 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child(int pipe_fds[], char *cmd, char **envp);

char	*ft_get_cmd_path(char *cmd, char **envp)
{
	int		pipe_fds[2];
	int		status;
	pid_t	parent;
	int		n_read;
	char	*ret_str;

	ret_str = (char *) malloc (sizeof(*ret_str) * 100);
	pipe(pipe_fds);
	parent = fork();
	if (parent < 0)
		perror("ft_get_cmd_path Fork: ");
	if (parent == 0)
		child(pipe_fds, cmd, envp);
	else
	{
		waitpid(parent, &status, 0);
		n_read = read(pipe_fds[0], ret_str, 100);
		if (n_read <= 0)
			perror("ft_get_cmd_path Parent Read: ");
		ret_str[n_read - 1] = '\0';
		close(pipe_fds[1]);
	}
	return (ret_str);
}

static void	child(int pipe_fds[], char *cmd, char **envp)
{
	char	*cmd_args[3];

	cmd_args[0] = "which";
	cmd_args[1] = cmd;
	cmd_args[2] = (char *) 0;
	if (dup2(pipe_fds[1], STDOUT_FILENO) < 0)
		return (perror("ft_get_cmd_path Child Dup2: "));
	close(pipe_fds[0]);
	execve ("/usr/bin/which", cmd_args, envp);
}
