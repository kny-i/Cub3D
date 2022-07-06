NAME = cub

srcs = $(wildcard ./*.c)
objs = $(srcs:.c=.o)
mlxpath = ./mlx_linux/
mlxflag = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
mlxmake = make -C $(mlxpath)
gitmlx	= 	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux


all: $(NAME)

$(mlxpath):
	$(gitmlx)

$(NAME): $(mlxpath) $(objs)
	$(mlxmake) 2> /dev/null
	cc $(objs) $(mlxflag) -o $(NAME)

mlx:
	$(mlxmake)

clean:
	$(mlxmake) clean
	rm -rf $(objs)

fclean: clean
	rm -rf $(mlxpath)/libmlx.a
	rm -rf $(NAME) $(objs)

re:	fclean all

test: all
	./cub

.PHONY: all clean fclean mlx re test