# **************************************************************************** #
#                                                                              #
#                               Makefile                                       #
#                                                                              #
#                          Abourenn -  	                                       #
#                                                                              #
# **************************************************************************** #

NAME = grilleEntiers

SRCPATH	=	src/

SRC		=	$(SRCPATH)main.c \
			$(SRCPATH)error.c \
			$(SRCPATH)initialisation.c \
			$(SRCPATH)parsing.c \
			$(SRCPATH)ft_base.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall\
		-lMLV\

HEADER = includes

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $^ -o $(NAME) -I $(HEADER)

%.o: %.c
	gcc $(FLAGS) -o $@ -c $^ -I $(HEADER)

clean:
	/bin/rm -rf $(OBJ)

fclean: clean
	/bin/rm -rf $(NAME)

re: fclean all
