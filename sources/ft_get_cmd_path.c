/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:06:27 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/24 00:14:58 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child(int *fd, char *cmd, char **envp);
static void	parent(int *fd, char *path);

void	ft_get_cmd_path(t_cmd *commands)
{
	int		status;
	int		pipe_fd[2];
	pid_t	child_pid;

	if (pipe(pipe_fd) < 0)
		error("pipe @ ft_get_cmd_path");
	child_pid = fork();
	if (child_pid < 0)
		error("child @ ft_get_cmd_path");
	if (child_pid == 0)
		child(pipe_fd, commands->arg[0], commands->envp);
	else
	{
		waitpid(child_pid, &status, 0);
		parent(pipe_fd, commands->path);
	}
	close(pipe_fd[READ_END]);
	close(pipe_fd[WRITE_END]);
}

static void	child(int *fd, char *cmd, char **envp)
{
	char	*cmd_args[3];

	cmd_args[0] = "which";
	cmd_args[1] = cmd;
	cmd_args[2] = NULL;
	close(fd[READ_END]);
	if (dup2(fd[WRITE_END], STDOUT_FILENO) < 0)
		error("dup2 @ child1 @ ft_get_cmd_path");
	if (execve ("/usr/bin/which", cmd_args, envp) < 0)
		error("execve @ child1 @ ft_get_cmd_path");
}

static void	parent(int *fd, char *cmd_path)
{
	int	n_read;

	close(fd[WRITE_END]);
	n_read = read(fd[READ_END], cmd_path, 100);
	if (n_read < 0)
		error("read @ child2 @ ft_get_cmd_path");
	else
	{
		if (n_read == 0)
			cmd_path = NULL;
		else
			cmd_path[n_read - 1] = '\0';
	}
}
