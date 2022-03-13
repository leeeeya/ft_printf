NAME = libftprintf.a

SRC = ft_bzero.c \
	  ft_calloc.c \
	  ft_memcpy.c \
	  ft_strlen.c \
	  ft_putchar_fd.c \
	  ft_putstr_fd.c \
	  ft_itoa.c \
      ft_printf.c \
	  ft_switch_else.c

FLAGS = -Wall -Wextra -Werror
OBJ = $(patsubst %.c,%.o,$(SRC))
HEADER = ft_printf.h

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
	ar rcs $(NAME) $?

$(OBJ) :%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re :  fclean all

.PHONY : all clean fclean re
