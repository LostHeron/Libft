NAME := libft.a
CC := cc
CFLAGS := -Wall -Wextra -Werror
INCLUDES := includes/

CHAR_DIR := src/char/
CHAR_FILES := ft_isalpha.c \
              ft_isdigit.c \
              ft_isalnum.c \
              ft_isascii.c \
              ft_isprint.c \
			  ft_toupper.c \
              ft_tolower.c \

MATH_DIR = src/math/
MATH_FILES = ft_power.c \
			 ft_abs.c \
			 ft_labs.c \

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

LIST_DC_DIR := src/lists/double_circular/
LIST_DC_FILES := ft_dc_node_new.c \
				 ft_dc_stack_add.c \
				 ft_dc_stack_add_back.c \
				 ft_dc_stack_rem.c \
				 ft_dc_stack_clear.c \
				 ft_dc_stack_print.c \

STRING_DIR := src/string/
STRING_FILES := ft_strlen.c \
				ft_strcpy.c \
				ft_strlcpy.c \
                ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strcmp.c \
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
				  ft_malloc.c \

IO_DIR := src/io/
IO_FILES := ft_putchar_fd.c \
            ft_putnbr_fd.c \
            ft_putunbr_fd.c \
            ft_putstr_fd.c \
            ft_putendl_fd.c \
			ft_putnbr_base_ull_fd.c \
			ft_putnbr_base_u_fd.c \
			ft_printf_utils2.c \
			ft_printf_utils1.c \
			ft_printf_fd.c \

GNL_DIR := src/io/get_next_line/
GNL_FILES := get_next_line.c \
			 get_next_line_utils.c \

VECTOR_DIR := src/vectors/
VECTOR_FILES := ft_vector_init.c \
				ft_vector_add_single.c \
				ft_vector_resize.c \
				ft_vector_free.c \

C_FILES := $(addprefix $(CHAR_DIR), $(CHAR_FILES)) \
		   $(addprefix $(MATH_DIR), $(MATH_FILES)) \
		   $(addprefix $(MEMORY_DIR), $(MEMORY_FILES)) \
		   $(addprefix $(LIST_SINGLE_DIR), $(LIST_SINGLE_FILES)) \
		   $(addprefix $(LIST_DC_DIR), $(LIST_DC_FILES)) \
		   $(addprefix $(STRING_DIR), $(STRING_FILES)) \
		   $(addprefix $(STANDARD_DIR), $(STANDARD_FILES)) \
		   $(addprefix $(IO_DIR), $(IO_FILES)) \
		   $(addprefix $(GNL_DIR), $(GNL_FILES)) \
		   $(addprefix $(VECTOR_DIR), $(VECTOR_FILES)) \

OBJ_DIR := .obj/
OBJ_FILES := $(addprefix $(OBJ_DIR), $(C_FILES:.c=.o))
DEPENDANCY_FILES := $(addprefix $(OBJ_DIR), $(C_FILES:.c=.d))


.PHONY: all clean fclean re test_dc

all: $(NAME)

$(NAME): $(OBJ_FILES) 
	ar rcs $(NAME) $^

-include $(DEPENDANCY_FILES)

$(OBJ_DIR)%.o: %.c | $(OBJ_DIR)$(CHAR_DIR) $(OBJ_DIR)$(MATH_DIR) $(OBJ_DIR)$(MEMORY_DIR) $(OBJ_DIR)$(LIST_DC_DIR) $(OBJ_DIR)$(LIST_SINGLE_DIR) $(OBJ_DIR)$(STRING_DIR) $(OBJ_DIR)$(STANDARD_DIR) $(OBJ_DIR)$(IO_DIR) $(OBJ_DIR)$(GNL_DIR) $(OBJ_DIR)$(VECTOR_DIR)
	$(CC) -c $(CFLAGS) -MMD -MP -I $(INCLUDES) $< -o $@

$(OBJ_DIR)$(MATH_DIR):
	mkdir -p $@

$(OBJ_DIR)$(CHAR_DIR):
	mkdir -p $@

$(OBJ_DIR)$(MEMORY_DIR):
	mkdir -p $@

$(OBJ_DIR)$(LIST_SINGLE_DIR):
	mkdir -p $@

$(OBJ_DIR)$(LIST_DC_DIR):
	mkdir -p $@

$(OBJ_DIR)$(STRING_DIR):
	mkdir -p $@

$(OBJ_DIR)$(STANDARD_DIR):
	mkdir -p $@

$(OBJ_DIR)$(IO_DIR):
	mkdir -p $@

$(OBJ_DIR)$(GNL_DIR):
	mkdir -p $@

$(OBJ_DIR)$(VECTOR_DIR):
	mkdir -p $@

clean:
	rm -rf $(OBJ_DIR)

fclean:
	$(MAKE) clean
	rm -f $(NAME)

re: fclean all

test_dc: $(NAME)
	$(MAKE) all
	$(CC) $(CFLAGS) -I $(INCLUDES) $(LIST_DC_DIR)test_dc.c -o test_dc.out $(NAME)

test : $(NAME)
	$(MAKE) all
	$(CC) $(CFLAGS) -I $(INCLUDES) test.c $(NAME)
