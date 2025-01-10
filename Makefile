NAME = push_swap
CC = cc -g
CCFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBFT_DIR = libft

SRC =	src/algo/reset_data.c src/algo/sort_stack.c src/algo/sort_three.c \
		src/moves/push.c src/moves/rotate.c src/moves/reverse_rotate.c \
		src/moves/swap.c src/utils/free.c src/utils/get_cheapest.c \
		src/utils/get_last.c src/utils/get_max.c src/utils/get_min.c\
		src/utils/init_stack_a.c src/utils/send_error.c src/utils/stack_len.c \
		src/utils/stack_sorted.c src/utils/update_pos.c src/main.c

# SRC_BONUS = 

OBJ = $(SRC:.c=.o)
#


all: $(LIBFT) $(NAME)

$(LIBFT):
	@$(MAKE) -C $(LIBFT_DIR) all

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

# bonus: $(LIBFT) $(OBJ_BONUS)	
# 	$(CC) $(CCFLAGS) $(OBJ_BONUS) -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c
	$(CC) $(FLAGS) -o $@ -c $^

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re 