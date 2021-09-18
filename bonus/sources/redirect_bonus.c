/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_one_redir(char *filename, int *fd)
{
	*fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (*fd < 0)
		exit_execve(filename);
}

void	ft_back_redir(char *filename, int *fd)
{
	*fd = open(filename, O_RDONLY);
	if (*fd < 0)
		exit_execve(filename);
}

void	ft_double_redir(char *filename, int *fd)
{
	*fd = open(filename, O_WRONLY | O_CREAT | O_APPEND, 0666);
	if (*fd < 0)
		exit_execve(filename);
}