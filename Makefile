.DEFAULT_GOAL := all
SRCS_EXEC = \

SRCS_BUILTIN = \

SRCS_PARSE = \

SRCS_ETC =

SRCS = \
	$(addprefix exec/, $(SRCS_EXEC)) \
	$(addprefix builtin/, $(SRCS_BUILTIN)) \
	$(addprefix parse/, $(SRCS_PARSE)) \
	$(SRCS_ETC)
LIBFT_DIR = libft
LIBFT_NAME = ft
LIBFT = libft/libft.a
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
CC = cc -MMD -MP -Wall -Wextra -Werror
MLX = -lmlx -framework OpenGL -framework AppKit
NAME = minishell
-include $(DEPS)

all :
	@echo "MINISHELL : make $(NAME)"
	@make $(NAME)

$(LIBFT) :
	@ echo "MINISHELL : make $(LIBFT)"
	@ make -C $(LIBFT_DIR)

$(NAME) : $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(OBJS) -l$(LIBFT_NAME) -L$(LIBFT_DIR) -lreadline

%.o : %.c
	@$(CC) -c $< -I$(LIBFT_DIR) -Iinclude -o $@

clean :
	@echo "MINISHELL : make clean"
	@rm -f $(OBJS) $(DEPS) $(BONUS)
	@make -C $(LIBFT_DIR) clean

fclean :
	@echo "MINISHELL : make fclean"
	@rm -f $(OBJS) $(NAME) $(DEPS)
	@make -C $(LIBFT_DIR) fclean

re : fclean
	@ echo "MINISHELL : make re"
	@make all

.PHONY: all clean fclean re
