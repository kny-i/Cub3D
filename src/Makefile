NAME = cub3d

srcs = $(wildcard ./*.c)
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
red='\033[0;31m'
green='\033[32m'
no='\033[0m'
###########[ok case]############

alltest: all
	bash ../test/test.sh 2>/dev/null

aok: all
	@./$(NAME) ../test/ok/ok.cub
	@echo $(green)"[ok case]"$(no)

bok: all
	@./$(NAME) ../test/ok/space_direction.cub
	@echo $(green)"[space direction format case]"$(no)

cok: all
	@./$(NAME) ../test/ok/space_FC.cub
	@echo $(green)"[space F C format case]"$(no)

dok: all
	@./$(NAME) ../test/ok/dup.cub
	@echo $(green)"[Priority is given to the one below]"$(no)

eok: all
	@./$(NAME) ../test/ok/jumbled_order.cub
	@echo $(green)"[order is not important]"$(no)

fok: all
	@./$(NAME) ../test/ok/space_in_map.cub
	@echo $(green)"[No problem with closed map]"$(no)


###########[ko case]#############
ako: all
	@echo $(red)"[not nbrs case]"$(no)
	@./$(NAME) ../test/ko/not_nbrs.cub

bko: all
	@echo $(red)"[invalid filename case]"$(no)
	@./$(NAME) ../test/ko/invalid_filename.abc

cko: all
	@echo $(red)"[invalid filename case]"$(no)
	@./$(NAME) ../test/ko/cub.cub.42

dko: all
	@echo $(red)"[invalid rgb case]"$(no)
	@./$(NAME) ../test/ko/invalid_rgb.cub

eko: all
	@echo $(red)"[invalid argument count case]"$(no)
	@./$(NAME)

fko: all
	@echo $(red)"[invalid map char]"$(no)
	@./$(NAME) ../test/ko/invalid_map_char.cub

gko: all
	@echo $(red)"[invalid map duplicate player]"$(no)
	@./$(NAME) ../test/ko/invalid_map_dup_player.cub

hko: all
	@echo $(red)"[invalid map not closed]"$(no)
	@./$(NAME) ../test/ko/invalid_map_not_closed.cub

iko: all
	@echo $(red)"[invalid map player outside map]"$(no)
	@./$(NAME) ../test/ko/invalid_map_player_outside.cub


.PHONY: all clean fclean mlx re test