NAME 		= push_swap
NAME_BONUS  = checker 
CC =		gcc
CFLAGS =	-g -Wall -Werror -Wextra
RM =		rm -rf

LIBFT_DIR =	./libft
LIBFT =		$(LIBFT_DIR)/libft.a

SRC_FILES =	arr_sort.c\
			check.c \
			init.c\
			list.c\
			print_list.c\
			push_swap.c\
			reverserotate.c\
			rotate.c\
			sort_big.c\
			sort_five.c\
			sort.c\
			swap.c\
			push.c
BONUS_FILES = arr_sort.c\
			check.c \
			init.c\
			list.c\
			print_list.c\
			push_swap.c\
			reverserotate.c\
			rotate.c\
			sort_big.c\
			sort_five.c\
			sort.c\
			swap.c\
			push.c

SRC    =    $(addprefix src/, $(SRC_FILES))
BONUS  =	$(addprefix bonus/, $(BONUS_FILES))


OBJECTS        =	$(SRC:.c=.o)
OBJECTS_BONUS  =    $(BONUS:.c=.o)

.c.o:
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(LIBFT) $(OBJECTS)  include/push_swap.h
			$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)

$(LIBFT):
			$(MAKE) -C $(LIBFT_DIR)

clean:
			$(MAKE) -C $(LIBFT_DIR) clean
			$(RM) $(OBJECTS) $(OBJECTS_BONUS)

fclean:		clean
			$(MAKE) -C $(LIBFT_DIR) fclean
			$(RM) $(NAME) $(NAME_BONUS)

re:			fclean all

bonus:		$(LIBFT) $(OBJECTS_BONUS) include/checker.h
			$(CC) $(CFLAGS) $(OBJECTS_BONUS) $(LIBFT) -o $(NAME_BONUS)


.PHONY:		all clean fclean re bonus