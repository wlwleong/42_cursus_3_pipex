/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_errorhandling_cmd.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 22:51:58 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/21 23:00:44 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char *argv[], char *envp[])
{
	char	*cmd[] = { "w", NULL };

	if (argc < 0 || argv[0] == NULL)
		exit(1);
	execve("/usr/bin/ls", cmd, envp);
	return (0);
}