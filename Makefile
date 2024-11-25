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
		   ft_strlcpy.c \
		   ft_strlcat.c \
		   ft_toupper.c \
		   ft_tolower.c \
		   ft_strchr.c \
		   ft_strrchr.c \
		   ft_strncmp.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_strnstr.c \
		   ft_atoi.c \
		   ft_calloc.c \
		   ft_strdup.c \
		   ft_substr.c \
		   ft_strjoin.c \
		   ft_strtrim.c \
		   ft_countwords.c \
		   ft_split.c \
		   ft_itoa.c \
		   ft_strmapi.c \
		   ft_striteri.c \
		   ft_putchar_fd.c \
		   ft_putnbr_fd.c \
		   ft_putstr_fd.c \
		   ft_putendl_fd.c \

OBJECTS := $(C_FILES:.c=.o)

C_FILES_BONUS := ft_lstnew_bonus.c \
				 ft_lstadd_front_bonus.c \
				 ft_lstsize_bonus.c \
				 ft_lstlast_bonus.c \
				 ft_lstadd_back_bonus.c \
				 ft_lstdelone_bonus.c \
				 ft_lstclear_bonus.c \

OBJECTS_BONUS := $(C_FILES_BONUS:.c=.o)

.PHONY: all clean fclean re bonus
all: $(NAME)

$(NAME): $(OBJECTS) 
	ar rcs $(NAME) $^

bonus: .bonus

.bonus: $(OBJECTS) $(OBJECTS_BONUS)
	@touch .bonus
	ar rcs $(NAME) $^

%.o: %.c libft.h 
	$(CC) -c $(FLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) $(OBJECTS_BONUS) .bonus

fclean: clean
	rm -f $(NAME)

re: fclean all
