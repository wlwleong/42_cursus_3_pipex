/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_errorhandling_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:51:58 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/21 23:00:44 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <errno.h>

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd[] = { "cat", NULL };
	int		fd;
	pid_t	child;
	int		status;

	if (argc < 0 || argv[0] == NULL)
		exit(1);
	fd = open("outfile", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
	{
		perror("error creating outfile");
		exit(errno);
	}
	if (dup2(fd, STDOUT_FILENO) < 0)
	{
		perror("error redirecting output");
		exit(errno);
	}
	close(fd);
	child = fork();
	if (child < 0)
	{
		perror("error creating child");
		exit(errno);
	}
	if (child == 0)
	{
		if (execve("/usr/bin/cat", cmd, envp) == -1)
		{
			perror("error executing command");
			exit(errno);
		}
	}
		close(STDOUT_FILENO);
	exit(EXIT_SUCCESS);
}