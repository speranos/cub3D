NAME = cub3D
CFLAGS = -Wall -Wextra -Werror
SRCS = args_check/*.c map_parsing/*.c ft_get_next_line/*.c *.c

all : $(NAME)
$(NAME): $(SRCS)
	@cc $(SRCS) $(CFLAGS) -o $(NAME)
	@echo YOU ARE READY TO GO ...!
clean :
	@rm -rf $(NAME)
	@echo CLEAN ...!
fclean : clean
	@echo RESET ...!
re : fclean all