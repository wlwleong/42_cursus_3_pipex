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

void    ft_fill_cmd(t_cmd *commands, int argc, char *argv[], char **envp);

int	main(int argc, char **argv, char **envp)
{
	int		pipe_fd[argc - 3 - 1][2];
//	pid_t	child[argc - 3];
	t_cmd	*cmds;
	int	i;

	i = 0;
	while (i < argc - 3)
	{
		if (pipe(pipe_fd[i]) < 0)
		{
			perror("error creating pipes!\n");
			exit(errno);
		}
		i++;
	}
	cmds = malloc ((argc - 3) * sizeof(t_cmd));
	ft_fill_cmd(cmds, argc, argv, envp);
	i = 0;
	while (i < argc - 3)
		print_commands(&cmds[i++]);
	return (0);
}
