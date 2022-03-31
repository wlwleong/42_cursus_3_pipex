/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:23:39 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/30 16:18:52 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	child(int infile_fd, int *pipe_fd, t_cmd *commands, int argc);
static void	parent(int outfile_fd, int *pipe_fd, t_cmd *commands, int argc);

int	main(int argc, char *argv[], char **envp)
{
	int		file_fd[2];
	int		pipe_fd[2];
	pid_t	child_pid;
	t_cmd	cmds[2];

	if (argc != 5)
		exit(EXIT_FAILURE);
	if (pipe(pipe_fd) < 0)
		error("error creating pipes");
	file_fd[INFILE] = ft_get_infile(argv[1]);
	file_fd[OUTFILE] = ft_get_outfile(argv[argc - 1]);
	ft_fill_cmd(cmds, argc, argv, envp);
	child_pid = fork();
	if (child_pid < 0)
		error("error creating child");
	if (child_pid == 0)
		child(file_fd[INFILE], pipe_fd, cmds, argc);
	else
	{
		waitpid(child_pid, NULL, 1);
		parent(file_fd[OUTFILE], pipe_fd, cmds, argc);
	}
	return (0);
}

static void	child(int infile_fd, int *pipe_fd, t_cmd *commands, int argc)
{
	if (dup2(infile_fd, STDIN_FILENO) < 0)
		error("error redirecting I of I/O (Child)");
	if (dup2(pipe_fd[WRITE_END], STDOUT_FILENO) < 0)
		error("error redirecting O of I/O (Child)");
	close(pipe_fd[READ_END]);
	if (execve(commands[0].path, commands[0].arg, commands[0].envp) < 0)
	{
		ft_putstr_fd(commands[0].arg[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_command(commands, argc);
		exit(127);
	}
}

static void	parent(int outfile_fd, int *pipe_fd, t_cmd *commands, int argc)
{
	if (dup2(pipe_fd[READ_END], STDIN_FILENO) < 0)
		error("error redirecting I of I/O (Parent)");
	if (dup2(outfile_fd, STDOUT_FILENO) < 0)
		error("error redirecting O of I/O (Parent)");
	close(pipe_fd[WRITE_END]);
	if (execve(commands[1].path, commands[1].arg, commands[1].envp) < 0)
	{
		ft_putstr_fd(commands[1].arg[0], 2);
		ft_putstr_fd(": command not found\n", 2);
		ft_free_command(commands, argc);
		exit(127);
	}
}
