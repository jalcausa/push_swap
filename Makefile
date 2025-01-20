CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = push_swap
SRC_DIR = src/
SRC = push_swap.c \
		init/arguments_check.c	\
		utils/free_memory.c		\
		utils/stack_creator.c	\
		operations/push.c		\
		operations/rotate.c		\
		operations/rrotate.c	\
		operations/swap.c
OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))


all: libft $(NAME)


$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/*.o
	@echo " ... push_swap compiled ..."

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/init
	@mkdir -p $(OBJS_DIR)/utils
	@mkdir -p $(OBJS_DIR)/operations
	@$(CC) $(FLAGS) -c $< -o $@

libft:
	@make -C libft/

clean:
	@$(RM) -r $(OBJS_DIR)
	@make -C libft/ clean
	@echo " ... Clean finished ..."

fclean: clean
	@$(RM) $(NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all bonus libft clean fclean re