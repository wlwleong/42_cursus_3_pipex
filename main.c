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

int	main(int argc, char **argv)
{
	int	fd1;
	int	fd2;

	if (argc < 5)
	{
		printf("Invalid input!\n");
		return (-1);
	}
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[4], O_WRONLY | O_CREAT, 0666);
	if (fd1 < 0 || fd2 < 0)
		return (-1);
	pipex(fd1, argv[2], argv[3], fd2);
	return (0);
}
