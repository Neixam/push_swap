# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:08:30 by ambouren          #+#    #+#              #
#    Updated: 2022/04/29 18:51:11 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc
DEPFLAGS=	-MT $@ -MMD -MP -MF $(DEP_PATH)/$*.d
CFLAGS  =	-Wall -Wextra -Werror
LDFLAGS	=	-lft -lftprintf -Llibs/
IFLAGS	=	-I includes/ -I libs/libft/includes/ -I libs/printf/includes/
EXEC	=	push_swap

INC_PATH=	includes/
DEP_PATH=	.deps/
OBJ_PATH=	objs/
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))

SRC		=	main.c
DEP		=	$(addprefix $(DEP_PATH), $(SRC:.c=.d))
OBJ		=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))

#	Compilation

$(EXEC)			:	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)%.o	:	%.c
	@mkdir -p $(DEP_PATH) $(OBJ_PATH)
	$(CC) $(DEPFLAGS) $(CFLAGS) -o $@ $^ $(IFLAGS)

$(DEP)			:

#	Rule

all		:	$(EXEC)

clean	:
	rm -rf $(OBJ_PATH)
	rm -rf $(DEP_PATH)

fclean	:	clean
	rm -rf $(EXEC)

re		:	fclean all

.PHONY	:	all clean fclean re
include $(DEP)
