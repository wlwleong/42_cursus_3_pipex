/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 00:04:17 by wlwleong          #+#    #+#             */
/*   Updated: 2022/04/03 00:04:37 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	child(int *pipe_fd, t_cmd *commands, int i);

int	pipex(t_cmd *commands)
{
	int		pipe_fd[2];
	pid_t	child_pid;
	int		i;

	i = 0;
	while (commands[i + 1].arg[0])
	{
		if (pipe(pipe_fd) < 0)
			error("error creating pipes");
		child_pid = fork();
		if (child_pid < 0)
			error("error creating child");
		if (child_pid == 0)
			child(pipe_fd, commands, i);
		else
		{
			waitpid(child_pid, NULL, 1);
			dup2(pipe_fd[READ_END], STDIN_FILENO);
			close(pipe_fd[WRITE_END]);
		}
		i++;
	}
	child(pipe_fd, commands, i);
	return (0);
}

static void	child(int *pipe_fd, t_cmd *commands, int i)
{
	if (i == 0)
		dup2(commands[i].infile_fd, STDIN_FILENO);
	if (commands[i].outfile_fd == -1)
		dup2(pipe_fd[WRITE_END], STDOUT_FILENO);
	else
		dup2(commands[i].outfile_fd, STDOUT_FILENO);
	close(pipe_fd[READ_END]);
	if (execve(commands[i].path, commands[i].arg, commands[i].envp) < 0)
	{
		ft_putstr_fd(commands[i].arg[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_command(commands);
		free(commands);
		exit(127);
	}
}
