NAME = cub3d

srcs = $(wildcard ./*.c)
objs = $(srcs:.c=.o)

### mlx ###
mlxpath = ./mlx_linux/
mlxflag = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
mlxmake = make -C $(mlxpath)
gitmlx	= 	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
############

debug_flag = -g -sanitize=address

all: $(NAME)

clone:
	$(gitmlx)

$(NAME): $(mlxpath) $(objs)
	$(mlxmake) 2> /dev/null
	cc $(objs) $(mlxflag) -o $(NAME)

mlx:
	$(mlxmake)

clean:
	$(mlxmake) clean
	$(RM) $(objs)

fclean: clean
	$(RM) $(mlxpath)/libmlx.a
	$(RM) $(NAME) $(objs)

re:	fclean all

#test: all
#	./$(NAME) dotcub/normal.cub
#
#out: all
#	./$(NAME) dotcub/normal.cub 2>/dev/null
#
#leaks: all
#	leaks -q --atExit -- ./$(NAME) dotcub/normal.cub

.PHONY: all clean fclean mlx re test