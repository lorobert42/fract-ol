# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2022/10/21 08:37:04 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fractol

SRCS	:=	fract-ol.c
OBJS	:=	$(SRCS:.c=.o)

LIBS	:=	ft mlx
LIBS_TARGET	:=	libft/libft.a /usr/local/lib/libmlx.a

INCS	:=	libft /usr/local/include

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
CPPFLAGS	:=	$(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS	:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS	:=	$(addprefix -l, $(LIBS))

RM		:=	rm -f

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME) -lXext -lX11

$(LIBS_TARGET):
	make bonus -C $(@D)

clean:
	for f in $(dir $(LIBS_TARGET)); do make -C $$f clean; done
	$(RM) $(OBJS)

fclean: clean
	for f in $(dir $(LIBS_TARGET)); do make -C $$f fclean; done
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
