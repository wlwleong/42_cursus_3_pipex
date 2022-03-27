/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 14:31:07 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/20 17:21:53 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_create_pipe(int *pipes[2], int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (pipe(pipes[i]) < 0)
		{
			perror("error creating pipes!\n");
			exit(errno);
		}
		i++;
	}
}

void	ft_dup2(int oldfd, int newfd)
{
	if (dup2(oldfd, newfd) < 0)
	{
		perror("error duplicating fd!\n");
		exit(errno);
	}
}

void    print_commands(t_cmd *cmd_struct)
{
    int j;

    printf("command path = %s\n", cmd_struct->path);
    j = 0;
    printf("command args = ");
    while(cmd_struct->arg[j])
        printf("%s,", cmd_struct->arg[j++]);
    printf("\n");
}

void	pipex(int index, int argc)
{
	if (index == 0)
		ft_dup2(ft_check_infile(argv[1]), )
}

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[(argc - 3) - 1][2];
	pid_t	child[argc - 3];
	t_cmd	*cmds;
	int	i;

	ft_create_pipe(pipe_fd, (argc - 3) - 1);
	cmds = malloc ((argc - 3) * sizeof(t_cmd));
	ft_fill_cmd(&cmds, argc, argv, envp);
	i = 0;
	while (i < argc - 3)
		print_commands(cmds[i++]);
	return (0);
}
