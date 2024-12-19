# =======================================
# Main Variables - Variables / Values
# =======================================

CC			=	cc
CFLAGS 		=	-Wall -Werror -Wextra
NAME		=	a.out

# =======================================
# Main Directories - Paths
# =======================================

LIBS		:=	ft_printf.h	libft.h push_swap.h
LIBS_TARGET := Libft/libft.a

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
	$(MAKE) 

OBJS	:= $(addprefix $(OBJ_D), $(OBJS))
SRCS	:= $(addprefix $(SRC_D), $(SRCS))

$(NAME):$(OBJS)
	$(CC) $(CFLAGS) includes/libft.a $(OBJS) -o $@

$(OBJ_D)%.o: $(SRC_D)%.c | $(OBJ_D)
	$(CC) $(CFLAGS) $(INC_D) -c $< -o $@

.PHONY: clean
clean:
	rm -rf $(OBJ_D)

.PHONY: fclean
fclean: clean
	rm -f $(NAME)

.PHONY: re
re:	fclean all

$(OBJ_D):
	mkdir -p $(OBJ_D)
