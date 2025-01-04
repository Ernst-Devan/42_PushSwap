# =======================================
# Main Variables - Variables / Values
# =======================================

CC			=	cc
NAME		=	a.out

# =======================================
# Main Directories - Paths
# =======================================

SRCS		=	push_swap.c \
				operations.c \
				parsing.c \

OBJS		= $(SRCS:.c=.o)

SRC_D		=	srcs/
OBJ_D		=	objs/
INC_D		=	-Iincludes \
				-ILibft/includes

CFLAGS 		=	-Wall -Werror -Wextra

# =======================================
# Objets Files
# =======================================

.PHONY: all
all: 
	$(MAKE) -C Libft
	$(MAKE) $(NAME)

OBJS	:= $(addprefix $(OBJ_D), $(OBJS))
SRCS	:= $(addprefix $(SRC_D), $(SRCS))

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) -Iincludes  $(OBJS) Libft/libft.a

$(OBJ_D)%.o: $(SRC_D)%.c Libft/libft.a | $(OBJ_D)
	$(CC) $(CFLAGS) $(INC_D) -c $< -o $@

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
