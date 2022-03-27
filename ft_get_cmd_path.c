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

#include "../pipex.h"

static void	child(int *fd, char *cmd, char **envp);
static void	parent(int *fd, char *path);

void	ft_get_cmd_path(t_cmd *commands)
{
	int		status;
	int		pipe_fd[2];
	pid_t	child_pid;

	if (pipe(pipe_fd) < 0)
	{
		perror("pipe @ ft_get_cmd_path");
		exit(errno);
	}
	child_pid = fork();
	if (child_pid < 0)
	{
		perror("child @ ft_get_cmd_path");
		exit(errno);
	}
	if (child_pid == 0)
		child(pipe_fd, commands->arg[0], commands->envp);
	else
	{
		waitpid(child_pid, &status, 0);
		parent(pipe_fd, commands->path);
	}
	close(pipe_fd[0]);
	close(pipe_fd[1]);
}

static void	child(int *fd, char *cmd, char **envp)
{
	char	*cmd_args[3];

	cmd_args[0] = "which";
	cmd_args[1] = cmd;
	cmd_args[2] = NULL;
	close(fd[0]);
	if (dup2(fd[1], STDOUT_FILENO) < 0)
	{
		perror("dup2 @ child1 @ ft_get_cmd_path");
		exit(errno);
	}
	close(fd[1]);
	if (execve ("/usr/bin/which", cmd_args, envp) < 0)
	{
		perror("execve @ child1 @ ft_get_cmd_path");
		exit(errno);
	}
}

static void	parent(int *fd, char *cmd_path)
{
	int	n_read;

	close(fd[1]);
	n_read = read(fd[0], cmd_path, 100);
	close(fd[0]);
	if (n_read < 0)
	{
		perror("read @ child2 @ ft_get_cmd_path");
		exit(errno);
	}
	else
	{
		if (n_read == 0)
			cmd_path = NULL;
		else
			cmd_path[n_read - 1] = '\0';
	}
}
