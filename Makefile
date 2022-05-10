NAME		= so_long

FLAGS		= -Wall -Wextra -Werror
INCL		= -I. -I./mlx -I./libft
LIB			= -L./libft -lft -L./mlx -lmlx -framework OpenGL -framework AppKit

SRCS_DIR	= srcs
OBJS_DIR	= $(shell mkdir -p objs && printf "objs")

SRCS		=	parsing.c			\
				parsing2.c			\
				parsing3.c			\
				main.c				\
				keyhook.c			\
				movement.c			\
				tiles.c				\
				exit.c

OBJS		= $(SRCS:%.c=$(OBJS_DIR)/%.o)

all :		$(NAME)

$(OBJS_DIR)/%.o :	$(SRCS_DIR)/%.c
	gcc $(FLAGS) $(INCL) -c $< -o $@

$(NAME) :	libft.a libmlx.a $(OBJS)
	gcc $(FLAGS) $(INCL) $(LIB) $(OBJS) -o so_long

libft.a :
	make -C ./libft

libmlx.a :
	@make -C ./mlx

clean :
	make fclean -C ./libft
	make clean -C ./mlx
	rm -rf $(OBJS_DIR)
	rm so_long

fclean : clean

re :		fclean all

.PHONY :	re all clean fclean
