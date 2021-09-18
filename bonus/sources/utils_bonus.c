/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void ft_argv_add_back(t_argv **ptr, t_argv *new)
{
    t_argv *tmp;

	if (!(*ptr))
		*ptr = new;
	else
	{
		tmp = *ptr;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
		new->prev = tmp;
	}
}

int ft_cmp(char *s1, char *s2)
{
    size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
    if (s1[i] != s2[i])
		return (0);
	return (1);
}

int	get_nstrs(char **str)
{
	int	n_strs;

	n_strs = 0;
	while (str[n_strs])
		n_strs++;
	return (n_strs);
}

char **copy_str_array(char **origin)
{
    char **new;
    int	nstrs;

	if (origin == NULL)
		exit_fatal();
	nstrs = get_nstrs(origin);
	new = (char **)malloc(sizeof(char *) * (nstrs + 1));
	if (new == NULL)
		exit_fatal();
    new[nstrs] = NULL;
    while (--nstrs >= 0)
        new[nstrs] = ft_strdup(origin[nstrs]);
    return (new);
}

/*
void debug_info(t_data *ptr)
{
	int i;
    t_argv *tmp;

    tmp = ptr->cmds;
    printf("MODE: %d\n", ptr->mode);
    printf("IN: %s\n", ptr->file_in);
    printf("OUT: %s\n", ptr->file_out);
    printf("STOP: %s\n", ptr->stop_value);
    printf("COMANDS: \n");
	while (tmp)
	{
		printf("=================\n");
		for (i = 0; i < tmp->size; i++)
			printf("%s\n", tmp->argv[i]);
		printf("SIZE: %d\n", tmp->size);
		printf("=================\n");
		tmp = tmp->next;
	}
    i = 0;
    printf("PATH: \n");
    while (ptr->env->path[i])
        printf("%s:", ptr->env->path[i++]);
	printf("\n=================\n");
}
*/
