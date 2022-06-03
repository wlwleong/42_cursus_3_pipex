/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 21:28:20 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/29 21:37:02 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

#define	READ 0
#define	WRITE 1

int	main(void)
{
	int	pipe_fd[2];
	pid_t	child;
	int	i;
	int	data;

	data = 1;
	i = 0;
	while (i < 10)
	{
		if (pipe(pipe_fd) < 0)
		{
			perror("error creating pipes");
			exit(errno);
		}		
		child = fork();
		if (child < 0)
		{
			perror("error creating child");
			exit(errno);
		}
		if (child == 0)
		{
			close(pipe_fd[READ]);
			data = data + 5;
			printf("Child %d with fd %d writing %d...\n", i, pipe_fd[WRITE], data);
			write(pipe_fd[WRITE], &data, sizeof(data));
			printf("child exiting...\n");
			return (0);
		}
		else
		{
			waitpid(child, NULL, 0);
			close(pipe_fd[WRITE]);
			read(pipe_fd[READ], &data, sizeof(data));
		}
		i++;	
	}
	return (0);
}
