.DEFAULT_GOAL := all
SRCS_EXEC = main.c

SRCS_PARSE =	parse.c \
				util.c \
				env.c \
				object.c \
				convert.c \
				verify.c

SRCS_CALCUL =	init_dim.c \
				cal_util.c

SRCS_LINEAR =	product.c \
				vector1.c \
				vector2.c \
				color.c \
				etc.c

SRCS_RENDER =	render.c \
				hook.c

SRCS_HIT 	=	hit.c \
				raytrace.c \
				util.c \
				solve.c \
				hit_cy.c \
				hit_shadow.c

SRCS_TRACE	=	phong.c

SRCS_GNL =	get_next_line.c \
			get_next_line_utils.c

SRCS = \
	$(addprefix get_next_line/, $(SRCS_GNL)) \
	$(addprefix src/parse/, $(SRCS_PARSE)) \
	$(addprefix src/calculate/, $(SRCS_CALCUL)) \
	$(addprefix src/linear/, $(SRCS_LINEAR)) \
	$(addprefix src/render/, $(SRCS_RENDER)) \
	$(addprefix src/hit/, $(SRCS_HIT)) \
	$(addprefix src/trace/, $(SRCS_TRACE)) \
	$(addprefix src/, $(SRCS_EXEC)) \
	$(SRCS_ETC)
LIBFT_DIR = libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
CC = cc -MMD -MP -Wall -Wextra -Werror #-fsanitize=address -g
MLX = mlx_macOS
MLX_FLAG = -lmlx -Lmlx -framework OpenGL -framework AppKit
NAME = miniRT
-include $(DEPS)

all :
	@echo "MINIRT : make $(NAME)"
	@make $(NAME)

$(MLX) :
	@ make -C mlx

$(LIBFT) :
	@ echo "MINIRT : make $(LIBFT)"
	@ make bonus -C $(LIBFT_DIR)

$(GNL_OBJS)

$(NAME) : $(MLX) $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) $(MLX_FLAG) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -lreadline

%.o : %.c
	@$(CC) -Imlx -c $< -I$(LIBFT_DIR) -Iinclude -o $@

clean :
	@echo "MINIRT : make clean"
	@rm -f $(OBJS) $(DEPS) $(BONUS)
	@make -C $(LIBFT_DIR) clean
	@make clean -C mlx

fclean :
	@echo "MINIRT : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)
	@make -C $(LIBFT_DIR) fclean
	@make clean -C mlx

re : fclean
	@ echo "MINIRT : make re"
	@make all

.PHONY: all clean fclean re
