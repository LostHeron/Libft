NAME := libft.a
CC := cc
FLAGS := -Wall -Wextra -Werror

C_FILES := ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_strlen.c \
		   ft_memset.c \
		   ft_bzero.c \
		   ft_memcpy.c \
		   ft_memmove.c \
		   ft_putchar_fd.c \
		   ft_putnbr_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \

OBJECTS := $(C_FILES:.c=.o)

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $^

$(OBJECTS): %.o: %.c libft.h
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
