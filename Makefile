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

BONUSDIR	= ./bonus/

LIBDIR		= ./libft/
LIBFT		= $(LIBDIR)libft.a

LIBFLAGS	= -L libft -lft 

CFLAGS		= -Wall -Wextra -Werror
CC			= clang

INCLUDES	= -I ./includes/. -I $(LIBDIR)includes/.
HEADER		= ./includes/pipex.h

SRCDIR		= ./sources/
OBJDIR		= ./objs/

FLS			= \
			main \
			parser \
			utils \
			errors \
			clears \
			exec_cmds \
			get_path \
			redirect

SRC			= $(FLS)

OBJ			= $(addprefix $(OBJDIR), $(SRC:=.o))
DFLS		= $(SRC:=.d)

all: $(LIBFT) | $(NAME)
	$(MAKE) $(NAME)

$(OBJ):			$(OBJDIR)%.o: $(SRCDIR)%.c $(HEADER)
	@$(CC)		$(CFLAGS) $(INCLUDES) -c $< -o $@ -MMD
	@echo "Compiled $@"

$(NAME):		$(OBJDIR) $(LIBFT) $(OBJ)
	@echo '----Making pipex ------'
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
	$(MAKE) clean	-C $(BONUSDIR)
	rm -rf		$(OBJDIR) *.o *.d

fclean:		clean
	$(MAKE) fclean	-C $(LIBDIR)
	$(MAKE) fclean	-C $(BONUSDIR)
	rm -f		$(NAME)
	rm -rf		.*.tmp *.tmp

re:		fclean
	$(MAKE)

norma:
	norminette $(SRCDIR) $(LIBDIR)srcs/*.c $(LIBDIR)includes/*.h ./includes/ \
				$(BONUSDIR)sources/*.c $(BONUSDIR)includes/*.h

bonus: fclean
	@echo '---Making bonus pipex ------'
	$(MAKE) -C $(BONUSDIR)
	cp $(BONUSDIR)$(NAME) .
	@echo 'Making bonus pipex done'

.PHONY: all debug clean fclean re bonus
