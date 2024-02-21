.DEFAULT_GOAL := all
SRCS_EXEC = main.c

SRCS_PARSE =	parse.c \
				file_control.c \
				error.c

SRCS_ETC = \

SRCS_GNL =	get_next_line.c \
			get_next_line_utils.c

SRCS = \
	$(addprefix get_next_line/, $(SRCS_GNL)) \
	$(addprefix src/parse/, $(SRCS_PARSE)) \
	$(addprefix src/, $(SRCS_EXEC)) \
	$(SRCS_ETC)
LIBFT_DIR = libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
CC = cc -MMD -MP -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = miniRT
-include $(DEPS)

all :
	@echo "MINIRT : make $(NAME)"
	@make $(NAME)

$(LIBFT) :
	@ echo "MINIRT : make $(LIBFT)"
	@ make -C $(LIBFT_DIR)

$(GNL_OBJS)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -lreadline

%.o : %.c
	@$(CC) -c $< -I$(LIBFT_DIR) -Iinclude -o $@

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
