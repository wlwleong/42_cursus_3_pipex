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

#include "../includes/pipex.h"

void	ft_fill_cmd(t_cmd *commands, int argc, char *argv[], char **envp)
{
	int	i;

	i = 0;
	while (argc - 3 - i > 0)
	{
		commands[i].envp = envp;
		commands[i].arg = ft_split(argv[i + 2], ' ');
		ft_get_cmd_path(&commands[i]);
		i++;
	}
}
