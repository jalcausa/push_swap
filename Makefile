CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -rf

NAME = push_swap
SRC_DIR = src/
SRC =	push_swap.c				\
		init/arguments_check.c	\
		utils/free_memory.c		\
		utils/stack_creator.c	\
		utils/print_stack.c		\
		operations/push.c		\
		operations/rotate.c		\
		operations/rrotate.c	\
		operations/swap.c		\
		sort/sort_utils.c		\
		sort/sort.c				\
		sort/quick_sort.c		\
		sort/move.c				\
		sort/chunk_split.c		\
		sort/chunk_utils.c

OBJS_DIR = objs/
OBJS = $(addprefix $(OBJS_DIR), $(SRC:.c=.o))

BONUS_NAME = checker
BONUS_SRC =	bonus/checker.c			\
			init/arguments_check.c	\
			operations/push.c		\
			operations/rotate.c		\
			operations/rrotate.c	\
			operations/swap.c		\
			utils/free_memory.c		\
			utils/stack_creator.c	\
			utils/print_stack.c		\
			sort/sort_utils.c		\
			sort/sort.c				\
			sort/quick_sort.c		\
			sort/move.c				\
			sort/chunk_split.c		\
			sort/chunk_utils.c

BONUS_OBJS = $(addprefix $(OBJS_DIR), $(BONUS_SRC:.c=.o))

all: libft objs $(NAME)

objs:
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)/init
	@mkdir -p $(OBJS_DIR)/utils
	@mkdir -p $(OBJS_DIR)/operations
	@mkdir -p $(OBJS_DIR)/sort

objs_bonus:
	@mkdir -p $(OBJS_DIR)/bonus

$(OBJS_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) -o $(NAME) $(OBJS) libft/*.o
	@echo " ... push_swap compiled ..."

libft:
	@make -C libft/

bonus: libft objs objs_bonus $(BONUS_OBJS)
	@$(CC) $(FLAGS) -o $(BONUS_NAME) $(BONUS_OBJS) libft/*.o
	@ echo "Checker compiled"

clean:
	@$(RM) objs $(OBJS) $(BONUS_OBJS)
	@make -C libft/ clean
	@echo " ... Clean finished ..."

fclean: clean
	@$(RM) objs $(NAME) $(BONUS_NAME)
	@make -C libft/ fclean

re: fclean all

.PHONY: all libft bonus clean fclean re