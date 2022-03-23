/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check_infile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:31:09 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/22 22:41:18 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_check_infile(char *file_path);

int	main(int argc, char *argv[])
{
	int	i;

	if (argc < 2)
	{
		printf("Invalid arguments!\n");
		return (-1);
	}
	i = 1;
	while (argc - i > 0)
	{
		if (ft_check_infile(argv[i]))
			printf("%s: file checked OK!\n", argv[i]);
		i++;
	}
	return (0);
}
