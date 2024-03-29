# **************************************************************************** #
#                                                                              #
#                               Makefile                                       #
#                                                                              #
#                          abourenn - chacelas                                 #
#                                                                              #
# **************************************************************************** #

NAME = grilleEntiers

SRCPATH	=	src/

SRC		=	$(SRCPATH)main.c \
			$(SRCPATH)error.c \
			$(SRCPATH)initialisation.c \
			$(SRCPATH)parsing.c \
			$(SRCPATH)ft_base.c \
			$(SRCPATH)game.c \
			$(SRCPATH)affiche.c \
			$(SRCPATH)jouer.c \
			$(SRCPATH)degringole.c \

OBJ = $(SRC:.c=.o)

FLAGS = -Wall\
		-Werror\
		-lMLV\
		-ansi\

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
