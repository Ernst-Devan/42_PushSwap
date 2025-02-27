# =======================================
# Main Variables - Variables / Values
# =======================================

CC			=	cc
NAME		=	push_swap
CCFLAGS 		?=	-Wall -Werror -Wextra

# =======================================
# Main Directories - Paths
# =======================================

SRCS		=	push_swap.c  \
				operations.c \
				parsing.c 	 \
				algorithm.c	 \
				pre_sort.c	 \
				sort.c	 \
				init.c

OBJS		= $(SRCS:.c=.o)

SRC_D		=	srcs/
OBJ_D		=	objs/
INC_D		=	-Iincludes \
				-ILibft/includes


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
	$(CC) $(CCFLAGS) -Iincludes  $(OBJS) Libft/libft.a -o $@

$(OBJ_D)%.o: $(SRC_D)%.c Libft/libft.a | $(OBJ_D)
	$(CC) $(CCFLAGS) $(INC_D) -c $< -o $@

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

debug:
	$(MAKE) CCFLAGS=' '