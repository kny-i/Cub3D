NAME = cub3d

srcs = free.c \
		game_init.c \
		get_step.c \
		init_ray.c \
		initialize_object.c \
		interception.c \
		judge_wall.c \
		key_settings.c \
		looking.c \
		main.c \
		message.c \
		moving.c \
		my_mlx_pixel_put.c \
		parse_utils.c \
		parser.c \
		play_gaming.c \
		ray_cast_utils.c \
		ray_casting.c \
		related_to_is.c \
		related_to_is2.c \
		related_to_is3.c \
		rendering.c \
		rendering_utils.c \
		update.c \
		utils.c \
		validate_map.c \
		validate_map_utils.c \
		xalloc.c

headers = $(wildcard *.h)
objs = $(srcs:.c=.o)

mlxpath = ./mlx_linux/
mlxflag = -Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -L/usr/X11R6/lib
mlxmake = make -C $(mlxpath)
CFLAGS = -Wextra -Werror -Wextra
debug_flag = -g3 -fsanitize=address
CC = cc

ifeq ($(MAKECMDGOALS), test)
TEST = -D TEST=0
endif

%.o: %.c
	@$(CC) $(CFLAGS) $(debug_flag) $(TEST) -c -o $@ $<

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
