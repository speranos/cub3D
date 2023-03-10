NAME		=	cub3D
CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror                                                                                                                                                                                                                                             -O3
SRCS		=	parsing/map_parsing/*.c parsing/args_check/*.c parsing/ft_get_next_line/*.c *.c raycasting/*.c

all			:	$(NAME)

$(NAME)		:	
				@$(CC) $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
				@echo "\033[32m\033[1m YOUR ARE READY TO GO ! \033[0m"
clean		:
				@rm -rf $(OBJS_M)
				@echo "\033[31m\033[1m All is clean ! \033[0m"

fclean		:	clean
				@rm -rf $(NAME)

re			:	fclean all