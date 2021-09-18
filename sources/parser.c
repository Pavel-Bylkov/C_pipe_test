/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int parser_argv(t_argv **ptr, char *av)
{
    t_argv *new;

	new = (t_argv *)malloc(sizeof(t_argv));
    if (!new)
        exit_fatal();
	new->argv = ft_split(av, ' ');
    if (!new->argv)
        exit_fatal();
    new->size = get_nstrs(new->argv);
	new->next = NULL;
	new->prev = NULL;
    ft_argv_add_back(ptr, new);
    return (new->size);
}

void get_path_from_env(t_data *data, char **envp)
{
	errno = 0;
	data->env = (t_env *)malloc(sizeof(t_env));
	if (!data->env)
		exit_fatal();
	data->env->env = copy_str_array(envp);
	data->env->path = get_path(envp);
}

void init_struct(t_data *data, int argc, char **argv, char **envp)
{
	int i;

	get_path_from_env(data, envp);
	data->mode = 1;
	i = 1;
	data->file_in = ft_strdup(argv[i++]);
	data->stop_value = NULL;
	if (ft_cmp(argv[1], "here_doc") && argc > 5)
		data->stop_value = ft_strdup(argv[i++ + --data->mode]);
	data->cmds = NULL;
	while (argv[i + 1])
		parser_argv(&data->cmds, argv[i++]);
	data->file_out = ft_strdup(argv[i]);
}
