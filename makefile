NAME		=	cub3D
BONUS		=	cub3D_bonus
CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror                                                                                                                                                                                                                                                                                                   -O3                                                                                                                                                                                                                                                                              
SRCS_M		=	Mandatory/parsing/map_parsing/*.c Mandatory/parsing/args_check/*.c Mandatory/parsing/ft_get_next_line/*.c Mandatory/*.c Mandatory/raycasting/*.c
SRCS_B		=	Bonus/parsing/map_parsing/*.c Bonus/parsing/args_check/*.c Bonus/parsing/ft_get_next_line/*.c Bonus/*.c Bonus/raycasting/*.c

all			:	$(NAME)

bonus		:	$(BONUS)

$(NAME)		:	$(SRCS_M)
				@$(CC) $(CFLAGS) $(SRCS_M) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
				@echo "\033[32m\033[1m [Mandatory part] YOUR ARE READY TO GO ! \033[0m"

$(BONUS)	:	fclean $(SRCS_B) 
				@$(CC) $(CFLAGS) $(SRCS_B) -lmlx -framework OpenGL -framework AppKit -o $(BONUS)
				@echo "\033[32m\033[1m [Bonus part] YOUR ARE READY TO GO ! \033[0m"

clean		:	
				@rm -rf $(OBJS_M)
				@rm -f $(OBJS_B)
				@echo "\033[31m\033[1m All is clean ! \033[0m"

fclean		:	clean
				@rm -rf $(NAME)
				@rm -rf $(BONUS)

re			:	fclean all