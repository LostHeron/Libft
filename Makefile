NAME := libft.a
NAME_DEBUG := libft_debug.a
CC := cc
CFLAGS_HARD = -Wall -Wextra -Werror -MMD -MP -ggdb3 -Wshadow -Wconversion -Wsign-conversion -Wmissing-prototypes \
-Wformat=2 -Wformat-security -Wnull-dereference -Wstack-protector -Wfloat-equal -Wpointer-arith \
-Wcast-align -Wundef -Wbad-function-cast -Wstrict-overflow=4 -Wdouble-promotion -Walloca -Wvla \
-Wwrite-strings -Wuninitialized -fno-delete-null-pointer-checks -fno-omit-frame-pointer -std=c11

#CFLAGS := -Wall -Wextra -Werror
CFLAGS := $(CFLAGS_HARD)
INCLUDES := includes/

CHAR_DIR := src/char/
CHAR_FILES := ft_isalpha.c \
              ft_isdigit.c \
              ft_isalnum.c \
              ft_isascii.c \
              ft_isprint.c \
			  ft_isspace.c \
			  ft_toupper.c \
              ft_tolower.c \

MATH_DIR = src/math/
MATH_FILES = ft_max.c \
			 ft_min.c \
			 ft_is_inf_d.c \
			 ft_is_nan_d.c \
			 ft_power.c \
			 ft_abs.c \
			 ft_abs_double.c \
			 ft_labs.c \
			 ft_cos.c \
			 ft_cos_adaptive.c \
			 ft_cos_iterative.c \
			 ft_get_nan.c \
			 ft_get_nanf.c \
			 ft_get_inf.c \
			 ft_get_inff.c \
			 ft_sin.c \
			 ft_tan.c \
			 ft_sqrt.c \
			 ft_sqrt_binary.c \
			 ft_sqrt_newton.c \

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
					 ft_s_lstrem_head.c \
					 ft_s_lstrem_last.c \

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
				ft_strncpy.c \
				ft_strcat.c \
				ft_strncat.c \
				ft_strlcpy.c \
                ft_strlcat.c \
				ft_strchr.c \
				ft_strrchr.c \
				ft_strcmp.c \
				ft_strncmp.c \
				ft_strnstr.c \
				ft_strstr.c \
				ft_strdup.c \
				ft_strndup.c \
				ft_substr.c \
				ft_strjoin.c \
				ft_strjoin_free_first.c \
				ft_strjoin_free_second.c \
				ft_strtrim.c \
				ft_strmapi.c \
				ft_striteri.c \

STANDARD_DIR := src/standard/
STANDARD_FILES := ft_atoi.c \
				  ft_atoi_safe.c \
				  ft_atof_safe.c \
                  ft_calloc.c \
				  ft_countwords.c \
				  ft_split.c \
				  ft_split_free.c \
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
			ft_print_binary_fd.c \

GNL_DIR := src/io/get_next_line/
GNL_FILES := get_next_line.c \
			 get_next_line_utils.c \

VECTOR_DIR := src/vectors/
VECTOR_FILES := ft_vector_init.c \
				ft_vector_add_single.c \
				ft_vector_add_multi.c \
				ft_vector_resize.c \
				ft_vector_free.c \
				ft_vector_copy.c \

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
