/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 15:22:39 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/30 15:25:24 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_command(t_cmd *commands, int argc)
{
	int	i;
	int	j;

	i = 0;
	while (argc - 3 - i > 0)
	{
		j = 0;
		while (commands[i].arg[j])
			free(commands[i].arg[j++]);
		free(commands[i++].arg);
	}
}
