/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 13:51:40 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/20 17:22:08 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_one(int pipe_fds[], int file1_fd, char **cmd1, char **envp);
static void	child_two(int pipe_fds[], int file2_fd, char **cmd2, char **envp);

void	pipex(int file1_fd, char *cmd[], int file2_fd, char **envp)
{
	int		pipe_fds[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	printf("Entering pipex...\n");
	pipe(pipe_fds);
	child1 = fork();
	if (child1 < 0)
		return (perror("child1 Fork: "));
	if (child1 == 0)
	{
		printf("Executing Child1...\n");
		child_one(pipe_fds, file1_fd, ft_split(cmd[2], ' '), envp);
		printf("Child1 done!\n");
	}
	child2 = fork();
	if (child2 < 0)
		return (perror("child2 Fork: "));
	if (child2 == 0)
	{
		printf("Executing Child2...\n");
		child_two(pipe_fds, file2_fd, ft_split(cmd[3], ' '), envp);
		printf("Child2 done!\n");
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

void	child_one(int pipe_fds[], int file1_fd, char **cmd1, char **envp)
{
	if (dup2(file1_fd, STDIN_FILENO) < 0)
		return (perror("child1 file1_fd Dup2: "));
	if (dup2(pipe_fds[1], STDOUT_FILENO) < 0)
		return (perror("child1 pipe_fds[1] Dup2: "));
	close(file1_fd);
	close(pipe_fds[0]);
	if (access(ft_get_cmd_path(cmd1[0], envp), X_OK) != 0)
		return (perror(cmd1[0]));
	execve (ft_get_cmd_path(cmd1[0], envp), cmd1, envp);
}

void	child_two(int pipe_fds[], int file2_fd, char **cmd2, char **envp)
{
	if (dup2(pipe_fds[0], STDIN_FILENO) < 0)
		return (perror("child2 pipe_fds[0] Dup2: "));
	if (dup2(file2_fd, STDOUT_FILENO) < 0)
		return (perror("child2 file2_fd Dup2: "));
	close(pipe_fds[1]);
	if (access(ft_get_cmd_path(cmd2[0], envp), X_OK) != 0)
		return (perror(cmd2[0]));
	execve (ft_get_cmd_path(cmd2[0], envp), cmd2, envp);
}
