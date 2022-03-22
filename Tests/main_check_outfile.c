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

int	ft_check_outfile(char *file_path);

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("Invalid arguments!\n");
		return (-1);
	}
	if (ft_check_outfile(argv[1]))
		printf("%s: file checked OK!\n", argv[1]);
	return (0);
}
