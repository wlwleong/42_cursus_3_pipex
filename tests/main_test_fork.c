/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_fork.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 22:27:42 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/25 22:28:28 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(void)
{
	int		status;
	pid_t	child1;
	pid_t	child2;

	child1 = fork();
	if (child1 < 0)
	{
		perror("Child1");
		exit(errno);
	}
	if (child1 == 0)
	{
		printf("Child1 created!\n");
		printf("Child1 exiting...\n");
	}
	if (child1 == 0)
		return (0);
	child2 = fork();
	if (child2 < 0)
	{
		perror("Child1");
		exit(errno);
	}
	if (child2 == 0)
	{
		printf("Child2 created!\n");
		printf("Child2 exiting...\n");
	}
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
	return (0);
}
