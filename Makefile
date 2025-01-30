SRCS = \
	src/main.c \
	src/push_swap.c \
	src/error.c \
	src/stack.c \
	src/sort_small.c \
	src/push.c \
	src/swap.c \
	src/utils.c \
	src/init.c \
	src/rotate.c \
	src/rev_rotate.c \

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJS_DIR = obj
OBJS = $(addprefix $(OBJS_DIR)/, $(notdir $(SRCS:.c=.o)))

NAME = push_swap

CC = gcc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -Ilibft

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus

$(OBJS_DIR)/%.o: src/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@make -C $(LIBFT_DIR) clean
	$(RM) -r $(OBJS_DIR)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

