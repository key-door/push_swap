NAME 		=	push_swap
CC			=	cc
CFLAGS		=	-I ./include -g -fsanitize=address -fsanitize=undefined
# CFLAGS		=	-Wall -Wextra -Werror -I ./include -g -fsanitize=address -fsanitize=undefined
# CFLAGS		=	-Wall -Wextra -Werror -I ./include
# CFLAGS		=	-I ./include
PRINTFDIR	=	ft_printf
PRINTF		=	$(PRINTFDIR)/libftprintf.a

SRCS		=	srcs/main.c \
				srcs/utils/utils.c \
				srcs/utils/ft_atol.c \
				srcs/list/list.c \
				srcs/list/list_del.c \
				srcs/utils/coordinate_compression.c \
				srcs/sort/sort_utlis.c \
				srcs/sort/sort.c \
				srcs/sort/min_sort.c \
				srcs/operation/stack_a_operation.c \
				srcs/operation/stack_b_operation.c \
				srcs/operation/stack_ab_operation.c \
				srcs/operation/stack_operation.c \



OBJDIR   = ./obj
OBJS  = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))


all: $(NAME)

$(NAME): $(OBJS) $(PRINTF)
		$(CC) -o $(NAME) $(SRCS) $(PRINTF) $(CFLAGS)

$(OBJDIR)/%.o: %.c
	@mkdir -p $$(dirname $@)
	$(CC) $(CFLAGS) -o $@ -c $<

printf:
		$(MAKE) -C $(PRINTFDIR)

clean:
		$(MAKE) clean -C $(PRINTFDIR)
		$(RM) ${OBJS}

fclean: clean
		$(MAKE) fclean -C $(PRINTFDIR)
		$(RM) ${NAME}

rmpu :
	$(RM) ${NAME}

re : fclean all

.PHONY:
		all clean fclean re

