# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: whector <whector@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/10 11:44:12 by whector           #+#    #+#              #
#    Updated: 2021/08/28 14:17:57 by whector          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

LIBDIR		= ../libft/
LIBFT		= $(LIBDIR)libft.a

LIBFLAGS	= -L$(LIBDIR) -lft 

CFLAGS		= -Wall -Wextra -Werror
CC			= clang

INCLUDES	= -I./includes/ -I$(LIBDIR)includes/
HEADER		= ./includes/pipex_bonus.h

SRCDIR		= ./sources/
OBJDIR		= ./objs/

FLS			= \
			main_bonus \
			parser_bonus \
			utils_bonus \
			errors_bonus \
			clears_bonus \
			exec_cmds_bonus \
			get_path_bonus \
			read_stdin_bonus \
			redirect_bonus

SRC			= $(FLS)

OBJ			= $(addprefix $(OBJDIR), $(SRC:=.o))
DFLS		= $(SRC:=.d)

all: $(LIBFT) | $(NAME)
	$(MAKE) $(NAME)

$(OBJ):			$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@$(CC)		$(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD
	@echo "Compiled $@"

$(NAME):		$(OBJDIR) $(LIBFT) $(OBJ)
	@echo '----Making pipex bonus ------'
	$(CC)		$(CFLAGS) $(INCLUDES) $(OBJ) $(LIBFLAGS) -o $(NAME)
	@echo "Ready"

$(OBJDIR):
	@mkdir -p $@

include $(wildcard $(addprefix $(OBJDIR), $(DFLS)))

$(LIBFT):
	@echo '---Making libft ------'
	$(MAKE) -C $(LIBDIR)
	@echo 'Making libft done'


clean:
	$(MAKE) clean	-C $(LIBDIR)
	rm -rf		$(OBJDIR) *.o *.d

fclean:		clean
	$(MAKE) fclean	-C $(LIBDIR)
	rm -f		$(NAME)
	rm -rf		.*.tmp *.tmp

re:		fclean
	$(MAKE)

.PHONY: all debug clean fclean re
