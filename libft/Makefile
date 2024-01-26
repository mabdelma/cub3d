NAME = libft.a
C_FLAGS = -Wall -Wextra -Werror -ggdb3

SRCS_DIR = sources/
SRCS_LIST = error-utils/ft_error.c \
			get_next_line/get_next_line.c \
			is-utils/ft_isalnum.c is-utils/ft_isalpha.c is-utils/ft_isascii.c is-utils/ft_isdigit.c is-utils/ft_isprint.c is-utils/ft_iswhitespace.c\
			memory-utils/ft_bzero.c memory-utils/ft_calloc.c memory-utils/ft_memchr.c memory-utils/ft_memcmp.c memory-utils/ft_memcpy.c \
			memory-utils/ft_memmove.c memory-utils/ft_memset.c memory-utils/ft_freeall.c \
			put-utils/ft_putendl_fd.c\
			string-utils/ft_split.c string-utils/ft_strchr.c string-utils/ft_strdup.c string-utils/ft_striteri.c string-utils/ft_strjoin.c \
			string-utils/ft_strlcat.c string-utils/ft_strlcpy.c string-utils/ft_strlen.c string-utils/ft_strmapi.c string-utils/ft_strncmp.c \
			string-utils/ft_strnstr.c string-utils/ft_strrchr.c string-utils/ft_strtrim.c string-utils/ft_substr.c
SRCS = $(addprefix $(SRCS_DIR), $(SRCS_LIST))
SUB_DIRS = error-utils ft_printf get_next_line is-utils linked-list memory-utils put-utils string-utils to-utils

OBJS_DIR = objects_files/
OBJS_SUBDIRS = $(foreach directory, $(SUB_DIRS), $(addprefix $(OBJS_DIR), $(directory)))
OBJS = $(subst $(SRCS_DIR), $(OBJS_DIR), $(SRCS:.c=.o))

### COLOURS
YELLOW = "\033[0;33m"
RESET = "\033[0m"

all : $(NAME)

$(NAME) : $(OBJS)
	@ar -rcs $(NAME) $^

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c
	@mkdir -p $(OBJS_DIR) $(OBJS_SUBDIRS)
	@$(CC) $(C_FLAGS) -I includes -c $< -o $@
	@echo $(YELLOW)".\c"$(RESET)

clean :
	@rm -rf $(OBJS_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
