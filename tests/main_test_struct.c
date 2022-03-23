/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 11:13:53 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/23 11:22:44 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s
{
	char	*infile;
	char	*outfile;
	char	*cmd;
}				t_struct;

void	print_struct(t_struct arg_file, t_struct arg_cmd[], int argc);
void	modify_struct(t_struct *arg_file, t_struct *arg_cmd[], int argc, char *argv[]);

int	main(int argc, char *argv[])
{
	t_struct	file_struct;
	t_struct	*cmd_struct;
	int			i;

	cmd_struct = malloc ((argc - 1) * sizeof(*cmd_struct));
	file_struct.infile = NULL;
	file_struct.outfile = NULL;
	i = 0;
	while (argc - i - 1 > 0)
		cmd_struct[i++].cmd = NULL;
	print_struct(file_struct, cmd_struct, argc);
	printf("\n");
	modify_struct(&file_struct, &cmd_struct, argc, argv);
	print_struct(file_struct, cmd_struct, argc);
	return (0);
}

void	print_struct(t_struct arg_file, t_struct arg_cmd[], int argc)
{
	int	i;

	printf("infile = %s\n", arg_file.infile);
	printf("outfile = %s\n", arg_file.outfile);
	i = 0;
	while (argc - i - 1 > 0)
	{
		printf("cmd%d = %s\n", i, arg_cmd[i].cmd);
		i++;
	}
}

void	modify_struct(t_struct *arg_file, t_struct *arg_cmd[], int argc, char *argv[])
{
	int	i;

	arg_file->infile = "infile";
	arg_file->outfile = "outfile";
	i = 0;
	while (argc - i - 1 > 0)
	{
		(*arg_cmd)[i].cmd = argv[i + 1];
		i++;
	}
}
