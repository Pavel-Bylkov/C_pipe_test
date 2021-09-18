/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whector <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:16:08 by whector           #+#    #+#             */
/*   Updated: 2021/03/24 15:16:13 by whector          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/stat.h> // open
# include <unistd.h> //access unlink close read write pipe dup execve fork exit
# include <fcntl.h> // open
# include <sys/types.h> // open waitpid wait fork
# include <sys/wait.h> // waitpid wait
# include <stdio.h> // perror
# include <errno.h> // perror
# include <stdlib.h> // malloc free exit
# include <string.h> // strerror
# include "libft.h"
# include "get_next_line.h"

# define STDIN	0
# define STDOUT	1
# define STDERR	2

typedef struct s_env
{
    char **path;
	char **env;
    int size;
} t_env;

typedef struct s_argv
{
    char **argv;
    int size;
	int fd[2];
	struct s_argv *prev;
    struct s_argv*next;
} t_argv;

typedef struct s_data
{
    t_argv *cmds;
	t_env *env;
    int mode;
    char *file_in;
    char *stop_value;
    char *file_out;
} t_data;

void init_struct(t_data *data, int argc, char **argv, char **envp);
void ft_argv_add_back(t_argv **ptr, t_argv *new);
void exit_fatal(void);
void exit_execve(char *str);
void exit_execve2(char *str);
int	ft_perror(int code, char *str1);
char **copy_str_array(char **origin);
int	get_nstrs(char **str);
char **get_path(char **envp);
void	free_struct(t_data *data);
void exec_cmds(t_data *data);
int ft_cmp(char *s1, char *s2);
char	*search_in_path(t_env *env, char *name);
void	ft_one_redir(char *filename, int *fd);
void	ft_back_redir(char *filename, int *fd);
void	ft_double_redir(char *filename, int *fd);

/*
int access(const char *pathname, int mode); mode - R_OK, W_OK, X_OK F_OK
int open(const char *pathname, int flags, mode_t mode);
int close(int fd);
int unlink(const char *pathname); 
ssize_t read(int fd, void *buf, size_t count);
ssize_t write(int fd, const void *buf, size_t count); 
void *malloc(size_t size);
void free(void *ptr);  
pid_t fork(void);   
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options); 
int pipe(int filedes[2]); 
int dup(int oldfd);
int dup2(int oldfd, int newfd);
int execve(const char *filename, char *const argv [], char *const envp[]);
void perror(const char *s); 
char *strerror(int errnum);
void exit(int status);
*/

#endif
