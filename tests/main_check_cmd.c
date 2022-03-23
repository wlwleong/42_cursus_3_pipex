/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_check_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wlwleong <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 22:06:27 by wlwleong          #+#    #+#             */
/*   Updated: 2022/03/23 22:06:33 by wlwleong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void    ft_get_cmd_path(t_cmd *cmd_struct);
void    ft_check_cmd(t_cmd *cmd_struct, int argc);
void    print_commands(t_cmd *cmd_struct[], int argc);

int main(int argc, char *argv[], char **envp)
{
    t_cmd   *commands;
    int     i;

    if (argc < 2)
        exit(-1);
    commands = malloc ((argc - 1) * sizeof(t_cmd));
    i = 0;
    while (argc - i - 1 > 0)
    {
        commands[i].envp = envp;
        commands[i].arg = ft_split(argv[i + 1], ' ');
        ft_get_cmd_path(&commands[i]);
        i++;
    }
    print_commands(&commands, argc);
    return (0);
}

void    print_commands(t_cmd *cmd_struct[], int argc)
{
    int i;
    int j;

    i = 0;
    while (argc - i - 1 > 0)
    {
        printf("command no.%d\n", i + 1);
        printf("command path = %s\n", (*cmd_struct)[i].path);
        j = 0;
        printf("command args = ");
        while((*cmd_struct)[i].arg[j])
            printf("%s,", (*cmd_struct)[i].arg[j++]);
        printf("\n");
        i++;
    }
}