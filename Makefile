# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: thloyan <thloyan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/30 21:58:17 by thloyan           #+#    #+#              #
#    Updated: 2023/06/12 15:34:44 by thloyan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

MLX = mlx

INCLUDES = includes
OBJDIR = .build
SRCDIR = srcs

CC = cc
DEPS := $(OBJECTS:.o=.d)
# CFLAGS = -g -Wall -Wextra -Werror -MMD -MP
CFLAGS = -g -MMD -MP

SRCS = 	main.c draw.c color.c utils.c \
		actions/move.c actions/zoom.c \
		events/key_handler.c events/mouse_handler.c \
		fractal/fractal.c fractal/mandelbrot.c fractal/julia.c fractal/burningship.c
OBJS = $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))


all: $(NAME)

$(NAME): $(OBJDIR) $(OBJS)
	$(CC) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME) $(OBJS) -I${INCLUDES} -Imlx

$(MLX):
	make -C $(MLX)
# mv $(MLX)/libmlx.a libmlx.a
# -Lmlx -lmlx -framework OpenGL -framework AppKit

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ -I${INCLUDES} -Imlx


$(OBJDIR):
	mkdir $(OBJDIR)

clean:
	make -C $(MLX) clean 
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: $(MLX) all $(NAME) clean fclean re
