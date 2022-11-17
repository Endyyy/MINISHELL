
LIBFT_PATH		=	./libs/libft
LIBFT			=	$(LIBFT_PATH)/libft.a

SOURCES_FILES	=	main.c				\
					ft_built_in.c		\
					ft_exec.c			\
					ft_clean_input.c	\
					ft_parse.c			\
					list.c				\
					list_1.c			\
					list_2.c			\
					check_data_cmd.c	\
					construct_list.c	\
					ft_init_env.c		\

SOURCES_DIR		=	srcs

HEADER			=	$(SOURCES_DIR)/mini.h

SOURCES			=	$(addprefix $(SOURCES_DIR)/, $(SOURCES_FILES))

OBJECTS			= 	$(SOURCES:.c=.o)

NAME			=	minishell

CC				=	gcc
RM				=	rm -f

CFLAGS			=	-g -Wall -Werror -Wextra

LFLAGS			=	-L/usr/local/lib -I/usr/local/include -lreadline

.c.o:
				$(CC) $(CFLAGS) $(LFLAGS) -c $< -o $(<:.c=.o)

all:			$(NAME)

$(NAME):		$(LIBFT) $(OBJECTS) $(HEADER)
				$(CC) $(CFLAGS) $(OBJECTS) $(LIBFT) -o $(NAME)  $(LFLAGS)

$(LIBFT):
				$(MAKE) -C $(LIBFT_PATH)

clean:
				$(MAKE) -C $(LIBFT_PATH) clean
				$(RM) $(OBJECTS)

fclean:			clean
				$(MAKE) -C $(LIBFT_PATH) fclean
				$(RM) $(NAME)

re:				fclean all

.SILENT:

.PHONY:			all clean fclean re libft
