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

int	main(int argc, char **argv, char **envp)
{
	int	fd1;
	int	fd2;

	if (argc < 5)
	{
		printf("Invalid input!\n");
		return (-1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (fd1 < 0)
	{
		perror(argv[1]);
		exit(1);
	}
	if (fd2 < 0)
	{
		perror(argv[4]);
		exit(1);
	}
	pipex(fd1, argv, fd2, envp);
	return (0);
}
