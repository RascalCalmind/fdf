# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lhageman <lhageman@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/03/27 19:52:54 by lhageman       #+#    #+#                 #
#    Updated: 2019/03/27 19:52:54 by lhageman      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = fdf
LIBFT = libft/
LIBM = minilibx_macos/

FLAGS = -Wall -Werror -Wextra

SRCS = fdfnew addtomap lstdelpos checkformat checklength fdfdel drawmap \
	fdfsetdefualt init windownew zoomset eventclose drawline posnew setcampos \
	drawlineyplus drawlinexplus calcpos color calcoffset zoomscale \
	eventmousedown inbounds imagepixelput calcpostoscreen puttext fitsonscreen \
	eventkeydown eventkeyup eventmouseup eventmousemove
SRCS := $(sort main.c $(SRCS:%=ft_%.c))

all: $(NAME)

$(NAME):
	-@make -C $(LIBFT)
	-@make -C $(LIBM)
	@echo "compiling fdf"
	@gcc -o $(NAME) $(FLAGS) $(SRCS) -I $(LIBM) -L $(LIBM) \
	-lmlx -L $(LIBFT) -lft -framework OpenGL -framework AppKit

clean:
	@make -C $(LIBM) clean
	@make -C $(LIBFT) clean

fclean: clean
	rm -rf fdf
	@make -C $(LIBFT) fclean

re: fclean all
	@make -C $(LIBM) re
	@make -C $(LIBFT) re

test:
	@rm -rf fdf
	@make
