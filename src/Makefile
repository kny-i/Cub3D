NAME = cub3d

srcs = $(wildcard *.c)
headers = $(wildcard *.h)
objs = $(srcs:.c=.o)

### mlx ###
mlxpath = ./mlx_linux/
mlxflag = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
mlxmake = make -C $(mlxpath)
CFLAGS = -Wextra

#######まさかのsanitizerをつけないとプログラムが正常に動かない#$
#debug_flag = -g3 -fsanitize=addresss
CC = cc

ifeq ($(MAKECMDGOALS), test)
TEST = -D TEST=0
endif

%.o: %.c
	$(CC) $(CFLAGS) $(debug_flag) $(TEST) -c -o $@ $<

all: $(NAME)

$(NAME): $(mlxpath) $(objs)
	@$(mlxmake) 2> /dev/null
	@make -C ../libft
	@$(CC) $(objs) ../libft/libft.a $(CFLAGS) $(mlxflag) $(debug_flag) -o $(NAME)

mlx:
	@$(mlxmake)

ok: all
	./$(NAME) ../test/ok/dup.cub

mini: all
	./$(NAME) ../test/ok/mini.cub

clean:
	@$(mlxmake) clean;
	@$(RM) $(objs)

fclean: clean
	@$(RM) $(mlxpath)/libmlx.a
	@$(RM) $(NAME) $(objs)

re:	fclean all

test: re
	@bash ../test/test.sh
	@make fclean >/dev/null

norm:
	@chmod -R 777 ../test/norm.sh
	@bash ../test/norm.sh

leak:
	@chmod -R 777 ../leak_check.sh
	@../leak_check.sh

.PHONY: all clean fclean mlx re test leak
