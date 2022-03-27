/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:31:07 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/27 21:19:33 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
	{
		perror("error duplicating fd!\n");
		exit(errno);
	}
}

void	print_commands(t_cmd *cmd_struct)
{
	int	j;

	printf("command path = %s\n", cmd_struct->path);
	j = 0;
	printf("command args = ");
	while (cmd_struct->arg[j])
		printf("%s,", cmd_struct->arg[j++]);
	printf("\n");
}

void	ft_close_pipes(int **pipe_fd, int argc)
{
	int	i;

	i = 0;
	while (i < N_COMMAND)
	{
		close(pipe_fd[i][0]);
		close(pipe_fd[i][1]);
		i++;
	}
}

void	pipex(int index, int **pipe_fd, int *file_fd, int argc);

int	main(int argc, char **argv, char **envp)
{
	int		**pipe_fd;
	int		file_fd[2];
	t_cmd	*cmds;
	pid_t	child[N_COMMAND];
	int	i;
	int	j;

	pipe_fd = (int **) malloc (sizeof(int *) * (N_COMMAND - 1));
	i = 0;
	while (i < N_COMMAND)
	{
		pipe_fd[i] = (int *) malloc (sizeof(int) * 2);
		if (pipe(pipe_fd[i]) < 0)
		{
			perror("error creating pipes!\n");
			exit(errno);
		}
		i++;
	}
	file_fd[0] = ft_get_infile(argv[0]);
	file_fd[1] = ft_get_outfile(argv[argc - 1]);
	cmds = malloc ((N_COMMAND) * sizeof(t_cmd));
	ft_fill_cmd(cmds, argc, argv, envp);
	i = 0;
	while (i < N_COMMAND)
	{
		child[i] = fork();
		if (child[i] < 0)
		{
			perror("error in forking!\n");
			exit(errno);
		}
		if (child[i] == 0)
		{
//			printf("Child %d created!\n", i);
			if (i == 0)
				ft_dup2(file_fd[0], STDIN_FILENO);
			else
				ft_dup2(pipe_fd[i][0], STDIN_FILENO);
			if (i == N_COMMAND - 1)
				ft_dup2(file_fd[1], STDOUT_FILENO);
			else
				ft_dup2(pipe_fd[i + 1][1], STDOUT_FILENO);
			ft_close_pipes(pipe_fd, argc);
			if (execve(cmds[i].path, cmds[i].arg, cmds[i].envp) < 0)
			{
				perror("error executing command(s)\n");
				exit(errno);
			}
		}
		j = 0;
		while (j++ < N_COMMAND)
			wait(NULL);
		i++;
	}
	free(pipe_fd);
	free(cmds);
	return (0);
}
