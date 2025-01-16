NAME = push_swap
NAME_BONUS = checker
CC = cc
CCFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
LIBFT_DIR = libft

SRC =	src/algo/reset_data.c src/algo/sort_stack.c src/algo/sort_three.c \
		src/moves/push.c src/moves/rotate.c src/moves/reverse_rotate.c \
		src/moves/swap.c src/utils/free.c src/utils/get_cheapest.c \
		src/utils/get_last.c src/utils/get_max.c src/utils/get_min.c\
		src/utils/init_stack_a.c src/utils/send_error.c src/utils/stack_len.c \
		src/utils/stack_sorted.c src/utils/update_pos.c src/main.c

SRC_BONUS = checker_bonus/parsing_bonus.c checker_bonus/main_bonus.c \
			checker_bonus/utils_bonus.c checker_bonus/get_next_line_bonus.c \
			checker_bonus/utils_1_bonus.c checker_bonus/push_bonus.c \
			checker_bonus/rotate_bonus.c checker_bonus/reverse_rotate_bonus.c \
			checker_bonus/swap_bonus.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@$(MAKE) -C $(LIBFT_DIR)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME) $(LIBFT_DIR)/$(LIBFT)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) bonus
	$(CC) $(CCFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS) $(LIBFT_DIR)/$(LIBFT)

%.o: %.c
	$(CC) $(CCFLAGS) -o $@ -c $^

clean:
	rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re 