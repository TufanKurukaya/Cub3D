NAME	=	libft.a
CC	=	cc
CFLAGS	=	 -Wall -Wextra -Werror
RM	=	rm -f

SRC	=	ft_atoi.c		\
		ft_bzero.c		\
		ft_calloc.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_putchar_fd.c	\
		ft_putendl_fd.c	\
		ft_putstr_fd.c	\
		ft_split.c		\
		ft_strchr.c		\
		ft_strdup.c		\
		ft_strjoin.c	\
		ft_strlen.c		\
		ft_strncmp.c	\
		ft_strrchr.c	\
		ft_strtrim.c	\
		ft_substr.c		\
		ft_memcpy.c		\

OBJ_DIR	=	../.objs/libft

OBJ = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all:	$(NAME)

$(NAME):	$(OBJ)
			@ar rcs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o : %.c
	@mkdir -p $(@D)
	@echo -e "\033[2J\033[H"
	@echo "\033[1;32mCompiling : \033[1;33m$<\033[0m"
	@sleep 0.01
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
			@$(RM) $(OBJ)

fclean:	clean
			@$(RM) $(NAME)

re:	fclean $(NAME)

.PHONY: all clean fclean re
