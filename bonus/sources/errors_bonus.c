/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void print_err(char *str)
{
	write(STDERR, str, ft_strlen(str));
}

int	ft_perror(int code, char *str1)
{
	print_err("pipex: ");
	if (str1)
		print_err(str1);
	print_err("\n");
	return (code);
}

void exit_fatal(void)
{
	perror("pipex: ");
	exit(EXIT_FAILURE);
}

void exit_execve(char *str)
{
	print_err("pipex: ");
	perror(str);
	exit(EXIT_FAILURE);
}

void exit_execve2(char *str)
{
	print_err("pipex: ");
	print_err(str);
	print_err(": command not found\n");
	exit(EXIT_FAILURE);
}