# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lorobert <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/10 14:40:57 by lorobert          #+#    #+#              #
#    Updated: 2022/11/09 10:35:59 by lorobert         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fractol

SRCS	:=	fract-ol.c \
			compute.c \
			mandelbrot.c \
			julia.c \
			colors.c \
			hooks.c \
			ft_atof.c
OBJS	:=	$(SRCS:.c=.o)

LIBS	:=	ft mlx
LIBS_TARGET	:=	libft/libft.a mlx/libmlx.a

INCS	:=	libft mlx

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror -g
CPPFLAGS	:=	$(addprefix -I, $(INCS)) -MMD -MP
LDFLAGS	:=	$(addprefix -L, $(dir $(LIBS_TARGET)))
LDLIBS	:=	$(addprefix -l, $(LIBS))

RM		:=	rm -f

UNAME	:=	$(shell uname)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS) $(LIBS_TARGET)
ifeq ($(UNAME),Linux)
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME) -lXext -lX11 -lm
else
	$(CC) $(LDFLAGS) $(OBJS) $(LDLIBS) -o $(NAME) -framework OpenGL -framework Appkit -lm
endif

$(LIBS_TARGET):
	make -C $(@D)

clean:
	make -C ./libft clean
	$(RM) $(OBJS)

fclean: clean
	make -C ./libft fclean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all bonus clean fclean re
