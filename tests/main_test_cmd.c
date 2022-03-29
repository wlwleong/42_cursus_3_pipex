/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_cmd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:23:39 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/29 13:37:45 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int argc, char *argv[], char **envp)
{
	int	child_status;
	int	pipe_fd[2];
	int	file_fd[2];
	pid_t	child;
	char	*cmd1[] = { "cat" };
	char	*cmd2[] = { "hostname", NULL };

	if (argc < 0 || argv == NULL)
		return (-1);
	child_status = 0;
	if (pipe(pipe_fd) < 0)
	{
		perror("error creating pipes");
		exit(errno);
	}
	file_fd[0] = open("infile", O_RDONLY);
	file_fd[1] = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	child = fork();
	if (child < 0)
	{
		perror("error creating child");
		exit(errno);
	}
	if (child == 0)
	{
		if (dup2(file_fd[0], STDIN_FILENO) < 0)
		{
			perror("error redirecting I of I/O (Child)");
			exit(errno);
		}
		if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
		{
			perror("error redirecting O of I/O (Child)");
			exit(errno);
		}
		close(pipe_fd[0]);
		if (execve("/usr/bin/cat", cmd1, envp) < 0)
		{
			child_status = -1;
			perror("error executing cmd1");
			exit(errno);
		}
	}
	else
	{
		waitpid(child, NULL, 0);
		printf("Child status = %d\n", child_status);	
		if (dup2(pipe_fd[0], STDIN_FILENO) < 0)
		{
			perror("error redirecting I of I/O (Parent)");
			exit(errno);
		}
		if (dup2(file_fd[1], STDOUT_FILENO) < 0)
		{
			perror("error redirecting O of I/O (Parent)");
			exit(errno);
		}
		close(pipe_fd[1]);
		printf("Child status = %d\n", child_status);
		if (execve("/usr/bin/hostname", cmd2, envp) < 0)
		{
			perror("error executing cmd2");
			exit(errno);
		}
	}
	return (0);
}
