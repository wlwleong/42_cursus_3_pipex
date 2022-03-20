/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_simple.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 01:12:58 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/20 14:38:06 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_get_cmd_path(char *cmd, char **envp);

int	main(int argc, char **argv, char **envp)
{
	if (argc < 2)
	{
		printf("Invalid input!\n");
		return (-1);
	}
	printf("output at main : %s\n", ft_get_cmd_path(argv[1], envp));
	return (0);
}
