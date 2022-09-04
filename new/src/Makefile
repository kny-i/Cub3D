NAME = cub3d

srcs = $(wildcard ./*.c)
objs = $(srcs:.c=.o)

### mlx ###
mlxpath = ./mlx_linux/
mlxflag = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
mlxmake = make -C $(mlxpath)
gitmlx	= 	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
############

#debug_flag = -g3 -fsanitize=address

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
debug1: all
	./$(NAME) ../test/test1.cub 1>/dev/null

debug2: all
	./$(NAME) ../test/test2.cub 1>/dev/null

debug3: all
	./$(NAME) ../test/test3.cub 1>/dev/null

debug4: all
	./$(NAME) ../test/test3.cub 1>/dev/null

leaks: all
	leaks -q --atExit -- ./$(NAME) ../test/test0.cub

.PHONY: all clean fclean mlx re test