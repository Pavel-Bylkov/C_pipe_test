/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_stdin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	write_lines_in_file(int fd, char *end)
{
	char		*line;
	int			ret;

	write(1, "> ", 2);
    line = NULL;
    ret = get_next_line(STDIN, &line);
	while (line && end && !ft_cmp(line, end) && ret > 0)
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
        free(line);
        line = NULL;
		write(1, "> ", 2);
        ret = get_next_line(STDIN, &line);
	}
	close(fd);
    if (line)
	    free(line);
    if (ret < 0)
        exit(ft_perror(130, "error read line in here-document mode"));
}

void	read_stdin(t_data *data)
{
	int		fd;

	fd = open(data->file_in, O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd > 0)
		write_lines_in_file(fd, data->stop_value);
	else
		exit(ft_perror(1, "error here-document mode start"));
}