NAME		= so_long

FLAGS		= -g -Wall -Wextra -Werror
INCL		= -I. -I./mlx -I./libft
LIB			= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		=	parsing.c	\
				parsing2.c	\
				main.c		\
				keyhook.c	\
				movement.c	\
				tiles.c		\
				exit.c		\



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
