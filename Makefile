.DEFAULT_GOAL := all
SRCS_EXEC = main.c

SRCS_PARSE =	parse.c \
				util.c \
				env.c \
				object.c \
				convert.c

SRCS_CALCUL =	init_dim.c \
				cal_util.c

SRCS_LINEAR =	product.c \
				vector.c \
				normalize.c

SRCS_RENDER =	render.c

SRCS_HIT 	=	hit.c \
				raytrace.c

SRCS_GNL =	get_next_line.c \
			get_next_line_utils.c

SRCS = \
	$(addprefix get_next_line/, $(SRCS_GNL)) \
	$(addprefix src/parse/, $(SRCS_PARSE)) \
	$(addprefix src/calculate/, $(SRCS_CALCUL)) \
	$(addprefix src/linear/, $(SRCS_LINEAR)) \
	$(addprefix src/render/, $(SRCS_RENDER)) \
	$(addprefix src/hit/, $(SRCS_HIT)) \
	$(addprefix src/, $(SRCS_EXEC)) \
	$(SRCS_ETC)
LIBFT_DIR = libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
CC = cc -MMD -MP -Wall -Wextra -Werror -fsanitize=address -g
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = miniRT
-include $(DEPS)

all :
	@echo "MINIRT : make $(NAME)"
	@make $(NAME)

$(LIBFT) :
	@ echo "MINIRT : make $(LIBFT)"
	@ make bonus -C $(LIBFT_DIR)

$(GNL_OBJS)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(MLX) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -lreadline

%.o : %.c
	@$(CC) -c $< -Imlx -I$(LIBFT_DIR) -Iinclude -o $@

clean :
	@echo "MINIRT : make clean"
	@rm -f $(OBJS) $(DEPS) $(BONUS)
	@make -C $(LIBFT_DIR) clean

fclean :
	@echo "MINIRT : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)
	@make -C $(LIBFT_DIR) fclean

re : fclean
	@ echo "MINIRT : make re"
	@make all

.PHONY: all clean fclean re
