NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
SRCS = parsing/args_check/*.c parsing/map_parsing/*.c parsing/ft_get_next_line/*.c *.c raycasting/*.c

all : $(NAME)

$(NAME) :
	@$(CC)  $(CFLAGS) $(SRCS) -lmlx -framework OpenGL -framework AppKit -o $(NAME)                                                                                                                                   
	@echo YOUR ARE READY TO GO !!!
clean :
	@rm -rf $(OBJS)
	@echo CLEAN !!!
fclean :
	@rm -rf $(NAME) $(OBJS)
	@echo RESET ...
re : fclean all