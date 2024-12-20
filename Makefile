# =======================================
# Main Variables - Variables / Values
# =======================================

CC			=	cc
CFLAGS 		=	-Wall -Werror -Wextra $(INC_D)
NAME		=	a.out

# =======================================
# Main Directories - Paths
# =======================================

SRCS		=				\
				push_swap.c	\
				operations.c

OBJS		= $(SRCS:.c=.o)

SRC_D		=	srcs/
OBJ_D		=	objs/
INC_D		=	-Iincludes \
				-ILibft/includes

# =======================================
# Objets Files
# =======================================


.PHONY: all
all: $(NAME)

OBJS	:= $(addprefix $(OBJ_D), $(OBJS))
SRCS	:= $(addprefix $(SRC_D), $(SRCS))

$(NAME):$(OBJS)
	$(MAKE) -C Libft
	cp Libft/libft.a .
	$(CC) $(CFLAGS) $< Libft/libft.a -o $@

$(OBJ_D)%.o: $(SRC_D)%.c | $(OBJ_D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_D)
	$(MAKE) clean -C Libft

.PHONY: fclean
fclean: clean
	rm -f $(NAME)
	rm -f libft.a
	$(MAKE) fclean -C Libft

.PHONY: re
re:	fclean all
	$(MAKE) re -C Libft

$(OBJ_D):
	mkdir -p $(OBJ_D)
