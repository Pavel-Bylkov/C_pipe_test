/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clears.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char **s)
{
	size_t	i;

	if (s != NULL)
	{
		i = 0;
		while (s[i] != NULL)
			free(s[i++]);
		free(s);
	}
}

void ft_argvclear(t_argv *ptr)
{
	t_argv *tmp;
	int i;

	while (ptr)
	{
		tmp = ptr->next;
		i = 0;
		while (ptr->argv[i])
			free(ptr->argv[i++]);
		free(ptr->argv);
		free(ptr);
		ptr = tmp;
	}
}

void ft_envclear(t_env *env)
{
	free_strs(env->env);
	free_strs(env->path);
	free(env);
}

void	free_struct(t_data *data)
{
	ft_argvclear(data->cmds);
	ft_envclear(data->env);
	free(data->file_in);
	free(data->file_out);
	if (data->stop_value)
		free(data->stop_value);
}

void	ft_free(void **content)
{
	if (*content != NULL)
	{
		free(*content);
		*content = NULL;
	}
}
