/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:23:39 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/30 16:18:52 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	main(int argc, char *argv[], char **envp)
{
	t_cmd	*cmds;

	if (argc < 5)
		exit(EXIT_FAILURE);
	ft_check_infile(argv[1]);
	ft_check_outfile(argv[argc - 1]);
	cmds = malloc ((argc - 3 + 1) * sizeof(t_cmd));
	ft_fill_cmd(cmds, argc, argv, envp);
	return (pipex(cmds));
}
