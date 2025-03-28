# =======================================
# Main Variables - Variables / Values
# =======================================

CC			=	cc
NAME		=	push_swap
CCFLAGS 		?=	-Wall -Werror -Wextra

# =======================================
# Main Directories - Paths
# =======================================

SRCS		=	push_swap.c		\
				operations_a.c	\
				operations_b.c	\
				operations_all.c\
				parsing.c		\
				pre_sort.c		\
				sort.c			\
				init.c			\
				limits.c		\
				fill_stack.c	\
				error.c			\
				utils.c			\

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
	$(CC) $(CCFLAGS) -Iincludes  $(OBJS) -lm Libft/libft.a -o $@

$(OBJ_D)%.o: $(SRC_D)%.c Libft/libft.a | $(OBJ_D) includes/push_swap.h
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
re:	fclean
	$(MAKE) re -C Libft
	$(MAKE)

$(OBJ_D):
	mkdir -p $(OBJ_D)

.PHONY: debug
debug:
	$(MAKE) CCFLAGS='-g3'