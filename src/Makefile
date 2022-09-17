NAME = cub3d

srcs = $(wildcard *.c)
headers = $(wildcard *.h)
objs = $(srcs:.c=.o)

### mlx ###
mlxpath = ./mlx_linux/
mlxflag = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
mlxmake = make -C $(mlxpath)
gitmlx	= 	git clone https://github.com/42Paris/minilibx-linux.git mlx_linux
#CFLAGS = -Wall -Werror -Wextra
############

debug_flag = -g3 -fsanitize=address
CC = cc

all: $(NAME)

clone:
	$(gitmlx)

$(NAME): $(mlxpath) $(objs)
	$(mlxmake) 2> /dev/null
	make -C ../libft
	$(CC) $(objs) ../libft/libft.a $(CFLAGS) $(mlxflag) $(debug_flag) -o $(NAME)

mlx:
	$(mlxmake)

clean:
	$(mlxmake) clean;
	$(RM) $(objs)

fclean: clean
	$(RM) $(mlxpath)/libmlx.a
	$(RM) $(NAME) $(objs)

re:	fclean all


leaks: all
	leaks -q --atExit -- ./$(NAME) ../test/test0.cub

test: all
	bash ../test/test.sh

norm:
	@chmod -R 777 ../test/norm.sh
	@bash ../test/norm.sh

#norm:
#	@norminette $(srcs) $(headers) > /dev/null
#	@echo $(green)"norm OK!"$(no)

.PHONY: all clean fclean mlx re test leaks