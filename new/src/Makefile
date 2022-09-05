NAME = cub3d

srcs = $(wildcard ./*.c)
objs = $(srcs:.c=.o)

### mlx ###
mlxpath = ./mlx_linux/
mlxflag = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
mlxmake = make -C $(mlxpath)
gitmlx	= 	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
############

debug_flag = -g3 -fsanitize=address

CC = cc

all: $(NAME)

clone:
	$(gitmlx)

$(NAME): $(mlxpath) $(objs)
	$(mlxmake) 2> /dev/null
	make -C ../libft
	$(CC) $(objs) ../libft/libft.a $(mlxflag) $(debug_flag) -o $(NAME)

mlx:
	$(mlxmake)

clean:
	$(mlxmake) clean;
	$(RM) $(objs)

fclean: clean
	$(RM) $(mlxpath)/libmlx.a
	$(RM) $(NAME) $(objs)

re:	fclean all

#################[debug]####################
success1: all
	cat ../test/normal/00_simple_20_13.cub
	./$(NAME) ../test/normal/00_simple_20_13.cub

success2: all
	cat ../test/normal/06_maxsize_256_256.cub
	./$(NAME) ../test/normal/06_maxsize_256_256.cub

failure1: all
	cat ../test/error/06_rgb_many_20_13.cub
	./$(NAME) ../test/error/06_rgb_many_20_13.cub

failure2: all
	cat ../test/error/08_design_invalid_color_20_13.cub
	./$(NAME) ../test/error/08_design_invalid_color_20_13.cub

leaks: all
	leaks -q --atExit -- ./$(NAME) ../test/test0.cub

.PHONY: all clean fclean mlx re test