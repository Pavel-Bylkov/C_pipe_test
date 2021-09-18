/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void child_exec(t_argv *tmp, t_data *data, int *fd, t_env *env)
{
    char *path;

    if (dup2(tmp->fd[STDOUT], STDOUT) < 0)
        exit_fatal();
    if (tmp->prev && dup2(tmp->prev->fd[STDIN], STDIN) < 0)
        exit_fatal();
    if (!tmp->prev)
    {
        ft_back_redir(data->file_in, &fd[STDIN]);
        if (fd[STDIN] > 2)
            dup2(fd[STDIN], STDIN);
    }
    if (!tmp->next)
    {
        if (data->mode)
            ft_one_redir(data->file_out, &fd[STDOUT]);
        else
            ft_double_redir(data->file_out, &fd[STDOUT]);
        if (fd[STDOUT] > 2)
            dup2(fd[STDOUT], STDOUT);
    }
    path = search_in_path(env, tmp->argv[0]);
    if ((execve(path, tmp->argv, env->env)) < 0)
        exit_execve2(tmp->argv[0]);
    free(path);
}

void parent_exec(t_argv *tmp, pid_t *pid, int *fd, int *status)
{
    waitpid(*pid, status, 0);
    close(tmp->fd[STDOUT]);
    if (!tmp->next)
    {
        close(tmp->fd[STDIN]);
        close(fd[STDOUT]);
    } 
    if (tmp->prev)
        close(tmp->prev->fd[STDIN]);
    else
        close(fd[STDIN]);
}

void exec_cmd(t_argv *tmp, t_env *env, t_data *data)
{
	pid_t pid;
	int status;
    int fd[2];

    if (pipe(tmp->fd))
        exit_fatal();
	pid = fork();
	if (pid < 0)
		exit_fatal();
	else if (pid == 0)
	{
        child_exec(tmp, data, fd, env);
		exit(EXIT_SUCCESS);
	}
	else
        parent_exec(tmp, &pid, fd, &status);
}

void exec_cmds(t_data *data)
{
    t_argv *tmp;

	tmp = data->cmds;
	while (tmp)
	{
		exec_cmd(tmp, data->env, data);
		tmp = tmp->next;
	}
}