NAME		= so_long

FLAGS		= -Wall -Wextra -Werror
INCL		= -I. -I./mlx -I./libft
LIB			= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS		= test.c

all :		${NAME}

${NAME} :	libft.a libmlx.a
	gcc ${FLAGS} ${INCL} ${LIB} ${SRCS} -o so_long

libft.a :
	make -C ./libft

libmlx.a :
	@make -C ./mlx
