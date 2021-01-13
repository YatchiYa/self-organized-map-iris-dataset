NAME = som_iris

CC = gcc

FLAGS = -lm 

SRC = 	main.c \
		srcs/get_line/get_line.c \
		srcs/free_and_exit/exit.c \
		srcs/tools/ft_get_nb_lines.c \
		srcs/tools/ft_split.c \
		srcs/parse/parce_data.c \
		srcs/tools/ft_endwith.c \
		srcs/parse/norm_data.c \
		pbplot/pbPlots.c \
		pbplot/supportLib.c \
		srcs/draw/draw_data.c \
		srcs/parse/get_limit_vector.c \
		srcs/tools/display_tab.c \
		srcs/tools/list_chaine.c \
		srcs/parse/write_on_file.c \
		srcs/parse/init_neurone.c \
		 srcs/parse/display_map_neurone.c \
		srcs/parse/init_data.c \
		srcs/parse/training_simulation.c \
		srcs/parse/init_learning.c \
		srcs/parse/training_simulation_extends.c



OBJS = $(SRC:.c=.o)

HEADER = includes/som.h includes/tols.h includes/get_line.h 

all: $(NAME)

$(NAME): $(SRC)
	$(CC) $(SRC) $(FLAGS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all