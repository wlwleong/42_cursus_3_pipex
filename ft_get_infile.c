/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_infile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:24:26 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/22 22:30:35 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_get_infile(char *file_path)
{
	int	fd;

	if (access(file_path, F_OK) != 0)
	{
		perror(file_path);
		exit(errno);
	}
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		perror(file_path);
		exit(errno);
	}
	return (fd);
}
