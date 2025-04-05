NAME = pipex

CC = cc

SRCS = srcs/errors.c srcs/get_path.c
INCLUDES = includes/pipex.h libft/libft.h

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

OBJ = $(SRCS:.c=.o)

CFLAGS = -Wall -Werror -Wall -g3 -I $(LIBFT_DIR)

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: clean fclean all re