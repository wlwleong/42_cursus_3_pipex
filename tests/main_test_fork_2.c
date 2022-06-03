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

#include "../includes/pipex.h"
#include <stdio.h>

void	ft_fork_test(void)
{
    int processID = fork();
	int	status;

    if (processID > 0)
        printf("This is the parent process, with ID: %d \n", getpid());
    else if (processID == 0)
        printf("This is a newly created child process with ID: %d   (Parent ID: %d)\n", getpid(), getppid());
    else
        printf("fork() returned a -ve value, so the fork system called failed and the child process could not be created\n");
    waitpid(processID, &status, 0);
	printf("This is a the last statement.\n");
}

int	main(void)
{
	ft_fork_test();
	ft_fork_test();
	ft_fork_test();
	return (0);
}