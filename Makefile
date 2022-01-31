NAME		= so_long

FLAGS		= -Wall -Wextra -Werror
INCL		= -I. -I./mlx -I./libft
LIB			= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		= parsing.c		\
				main.c		\


all :		${NAME}

${NAME} :	libft.a libmlx.a
	gcc ${FLAGS} ${INCL} ${LIB} ${SRCS} -o so_long

libft.a :
	make -C ./libft

libmlx.a :
	@make -C ./mlx

clean :
	make fclean -C ./libft
	make clean -C ./mlx
	rm so_long

re :		fclean all

.PHONY :	re all clean
