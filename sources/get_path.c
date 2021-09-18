/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_path(char **envp)
{
	char	**path;
	int		i;

	path = NULL;
	if (envp)
	{
		i = -1;
		while (envp[++i] != NULL)
			if (ft_strncmp(envp[i], "PATH=", 5) == 0)
				path = ft_split(&envp[i][5], ':');
	}
    if (!path)
        exit(ft_perror(1, "Cannot found PATH variable in ENV"));
	return (path);
}

char	*ft_newpath(char *dir, char *name)
{
	char	*res;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	res = ft_strjoin(tmp, name);
	free(tmp);
	return (res);
}

char	*get_abs_path(char **path, char *name, int *flag)
{
	int		i;
	int		fd;
    char	*abs_path;

	i = 0;
	*flag = 0;
	while (path[i] && *flag == 0)
	{
		abs_path = ft_newpath(path[i], name);
		fd = open(abs_path, O_RDONLY);
		if (fd > 0)
		{
			*flag = 1;
			close(fd);
		}
		else
			free(abs_path);
		i++;
	}
	return (abs_path);
}

char	*search_in_path(t_env *env, char *name)
{
	char	*abs_path;
	int		flag;

	if (env->path)
	{
		abs_path = get_abs_path(env->path, name, &flag);
		if (flag)
		{
			free(name);
			return (abs_path);
		}
	}
	return (name);
}
