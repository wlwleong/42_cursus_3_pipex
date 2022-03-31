/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 21:28:25 by wlow              #+#    #+#             */
/*   Updated: 2021/08/04 00:04:44 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	unsigned int	index;

	if (s)
	{
		index = 0;
		while (s[index] != '\0')
			write(fd, &s[index++], 1);
	}
}
