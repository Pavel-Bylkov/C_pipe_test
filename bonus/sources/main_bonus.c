/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_data	data;

	if (argc < 5)
		return (ft_perror(1, "error number of arguments - must be four and more!"));
	init_struct(&data, argc, argv, envp);
	if (data.mode == 0)
		read_stdin(&data);
	//debug_info(&data);
	exec_cmds(&data);
	free_struct(&data);
	return (0);
}
