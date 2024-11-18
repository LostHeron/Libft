NAME := libft.a
CC := cc
FLAGS := -Wall -Wextra -Werror

C_FILES := ft_isalpha.c \
		   ft_isdigit.c \
		   ft_isalnum.c \
		   ft_isascii.c \
		   ft_isprint.c \
		   ft_strlen.c \
		   ft_memset.c

OBJECTS := $(C_FILES:.c=.o)

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $^

$(OBJECTS): %.o: %.c libft.h
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm *.o

fclean: clean
	rm $(NAME)

re: fclean all
