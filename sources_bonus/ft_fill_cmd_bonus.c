/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:06:27 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/27 21:05:48 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	ft_fill_cmd(t_cmd *commands, int argc, char *argv[], char **envp)
{
	int	i;

	i = 0;
	while (argc - 3 - i > 0)
	{
		if (i == 0)
			commands[i].infile_fd = open(argv[1], O_RDONLY);
		else
			commands[i].infile_fd = -1;
		if (i == argc - 3 - 1)
			commands[i].outfile_fd = open(argv[argc - 1],
					O_WRONLY | O_CREAT | O_TRUNC, 0644);
		else
			commands[i].outfile_fd = -1;
		commands[i].envp = envp;
		commands[i].arg = ft_split(argv[i + 2], ' ');
		ft_get_cmd_path(&commands[i]);
		i++;
	}
	commands[i].arg = malloc (sizeof(char *));
	commands[i].arg[0] = NULL;
}
