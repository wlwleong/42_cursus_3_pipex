/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlow <wlow@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 09:21:07 by wlow              #+#    #+#             */
/*   Updated: 2021/08/05 09:22:47 by wlow             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	ft_get_n_str(char const *s, char c);
static char	*ft_new_str(char const *s, int start, int end);

char	**ft_split(char const *s, char c)
{
	char	**strs;
	int		n_str;
	int		start;
	int		i;

	if (!s)
		return (NULL);
	n_str = ft_get_n_str(s, c);
	strs = (char **) malloc (sizeof(*strs) * (n_str + 1));
	if (!strs)
		return (NULL);
	n_str = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (i - start > 0)
			strs[n_str++] = ft_new_str(s, start, i);
	}
	strs[n_str] = NULL;
	return (strs);
}

static int	ft_get_n_str(char const *s, char c)
{
	int	n_str;
	int	index;
	int	i_before;

	n_str = 0;
	index = 0;
	while (s[index])
	{
		while (s[index] == c)
			index++;
		i_before = index;
		while (s[index] != c && s[index])
			index++;
		if (index - i_before > 0)
			n_str++;
	}
	return (n_str);
}

static char	*ft_new_str(char const *s, int start, int end)
{
	char	*new_str;
	int		index;

	new_str = (char *) malloc (sizeof(*new_str) * (end - start + 1));
	if (!new_str)
		return (NULL);
	index = 0;
	while (index < end - start)
	{
		new_str[index] = s[start + index];
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
