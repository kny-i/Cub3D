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

#################[easy compile && debug]####################
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


###########[tester]#####################
green='\033[32m'
no='\033[0m'

###########[ok case]############
aok: all
	@./$(NAME) ../test/ok/ok.cub
	@echo $(green)"[ok case]"$(no)

bok: all
	@echo $(green)"[space direction format case]"$(no)
	@./$(NAME) ../test/ok/space_direction.cub


###########[ko case]#############
ako: all
	@echo $(green)"[not nbrs case]"$(no)
	@./$(NAME) ../test/ko/not_nbrs.cub

bko: all
	@echo $(green)"[invalid filename case]"$(no)
	@./$(NAME) ../test/ko/invalid_filename.abc

cko: all
	@echo $(green)"[invalid filename case]"$(no)
	@./$(NAME) ../test/ko/cub.cub.42

dko: all
	@echo $(green)"[invalid rgb case]"$(no)
	@./$(NAME) ../test/ko/invalid_rgb.cub

eko: all
	@echo $(green)"[invalid argument count case]"$(no)
	@./$(NAME)


##############[map test]###############

####一気にテストできるような.shをあとで書く予定

.PHONY: all clean fclean mlx re test