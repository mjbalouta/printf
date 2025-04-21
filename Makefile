
CC 			= cc
CFLAGS		= -Wall -Wextra -Werror -I./Libft
NAME		= libftprintf.a

SRCS		= libftprintf.c ft_printletters.c ft_printnumbers.c
OBJS		= $(SRCS:.c=.o)
LIBFT_DIR 	= ./Libft
LIBFT 		= ./Libft/libft.a

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@@echo "Compiling all files..."
#cp copies libft library to the final output
	@cp $(LIBFT) $(NAME) 
	@ar rcs $(NAME) $(OBJS)
#this tool creates and index for the static library
	@ranlib $(NAME)

$(LIBFT): $(LIBFT_SRC)
	@@echo "Compiling libft..."
#libft depends on libft_dir: if libft is out of date, make will update it
#this make refers to the libft makefile (-C tells make to change directory to libft_dir)
	@$(MAKE) -C $(LIBFT_DIR)

%.o: %.c libftprintf.h
	@$(CC) $(CFLAGS) -c $< -o $@ 

clean:
	@@echo "Removing objects..."
	@$(MAKE) clean -C $(LIBFT_DIR)
	@rm -f $(OBJS) 

fclean: clean
	@@echo "Removing library..."
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re bonus