# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ambouren <ambouren@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/29 17:08:30 by ambouren          #+#    #+#              #
#    Updated: 2022/06/13 18:17:30 by ambouren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#  Variable
purple	=	\033[0;35m
cyan	=	\033[0;36m
green	=	\033[0;32m
neutral	=	\033[0m
red		=	\033[31m

CC      =	gcc

CFLAGS  =	-Wall -Wextra -Werror -g
IFLAGS	=	-I includes/
EXEC	=	push_swap

INC_PATH=	includes/
DEP_PATH=	deps/
OBJ_PATH=	objs/
SRC_PATH=	$(shell find srcs -type d)
vpath %.c $(foreach rep, $(SRC_PATH), $(rep))

SRC		=	main.c \
			utils.c \
			data.c \
			parsing.c \
			list.c \
			ft_split.c \
			swap.c \
			push.c \
			rotate.c \
			reverse_r.c \
			resolve.c \
			resolve_less_than.c \
			radix_sort.c \
			abs.c
DEP		=	$(addprefix $(DEP_PATH), $(SRC:.c=.d))
OBJ		=	$(addprefix $(OBJ_PATH), $(SRC:.c=.o))

#	Compilation
$(EXEC)			:	$(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_PATH)%.o	:	%.c
	@mkdir -p $(OBJ_PATH) $(DEP_PATH)
	$(CC) -o $@ -c $< $(CFLAGS) $(IFLAGS) -MMD
	@mv $(@:.o=.d) $(DEP_PATH)

-include $(DEP)

#	Rule

all		:	$(EXEC)

clean	:
	rm -rf $(OBJ_PATH)
	rm -rf $(DEP_PATH)

fclean	:	clean
	rm -rf $(EXEC)

re		:	fclean all

.PHONY	:	all clean fclean re