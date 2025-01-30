NAME := libft.a
CC := cc
FLAGS := -Wall -Wextra -Werror


CHAR_DIR := src/char/
CHAR_FILES := ft_isalpha.c \
              ft_isdigit.c \
              ft_isalnum.c \
              ft_isascii.c \
              ft_isprint.c \
			  ft_toupper.c \
              ft_tolower.c \

MEMORY_DIR := src/memory/
MEMORY_FILES := ft_memset.c \
                ft_bzero.c \
                ft_memcpy.c \
				ft_memmove.c \
				ft_memchr.c \
				ft_memcmp.c \

LIST_SINGLE_DIR := src/lists/single/
LIST_SINGLE_FILES := ft_s_lstnew.c \
					 ft_s_lstadd_front.c \
			  		 ft_s_lstsize.c \
			  		 ft_s_lstlast.c \
			  		 ft_s_lstadd_back.c \
			  		 ft_s_lstdelone.c \
			  		 ft_s_lstclear.c \
			  		 ft_s_lstiter.c \
			  		 ft_s_lstmap.c \

STRING_DIR := src/string/
STRING_FILES := ft_strlen.c \
				ft_strlcpy.c \
                ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strdup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_striteri.c \

STANDARD_DIR := src/standard/
STANDARD_FILES := ft_atoi.c \
                  ft_calloc.c \
				  ft_countwords.c \
				  ft_split.c \
				  ft_itoa.c \

IO_DIR := src/io/
IO_FILES := ft_putchar_fd.c \
            ft_putnbr_fd.c \
            ft_putunbr_fd.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c \

C_FILES := $(addprefix $(CHAR_DIR), $(CHAR_FILES)) \
		   $(addprefix $(MEMORY_DIR), $(MEMORY_FILES)) \
		   $(addprefix $(LIST_SINGLE_DIR), $(LIST_SINGLE_FILES)) \
		   $(addprefix $(STRING_DIR), $(STRING_FILES)) \
		   $(addprefix $(STANDARD_DIR), $(STANDARD_FILES)) \
		   $(addprefix $(IO_DIR), $(IO_FILES)) \

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEPENDANCY_FILES := $(addprefix $(OBJ_DIR), $(C_FILES:.c=.d))


.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ_FILES) 
	ar rcs $(NAME) $^

-include $(DEPENDANCY_FILES)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)$(CHAR_DIR) $(OBJ_DIR)$(MEMORY_DIR) $(OBJ_DIR)$(LIST_SINGLE_DIR) $(OBJ_DIR)$(STRING_DIR) $(OBJ_DIR)$(STANDARD_DIR) $(OBJ_DIR)$(IO_DIR) 
	$(CC) -c $(FLAGS) -MMD -MP -I includes $< -o $@

$(OBJ_DIR)$(CHAR_DIR):
	mkdir -p $@

$(OBJ_DIR)$(MEMORY_DIR):
	mkdir -p $@

$(OBJ_DIR)$(LIST_SINGLE_DIR):
	mkdir -p $@

$(OBJ_DIR)$(STRING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(STANDARD_DIR):
	mkdir -p $@

$(OBJ_DIR)$(IO_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re: fclean all
