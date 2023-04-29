# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: osabir <osabir@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/23 15:05:35 by osabir            #+#    #+#              #
#    Updated: 2023/03/28 15:57:40 by osabir           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 

SRC1 = ./mandatory/so_long.c ./mandatory/ft_tools_1.c ./mandatory/ft_tools_2.c ./mandatory/ft_tools_3.c ./mandatory/get_next_line.c \
		./mandatory/get_next_line_utils.c ./mandatory/ft_split.c ./mandatory/valid_path.c ./mandatory/ft_tools_4.c \
		./mandatory/ft_tools_5.c ./mandatory/ft_tools_6.c ./mandatory/ft_tools_7.c ./mandatory/ft_tools_8.c ./mandatory/ft_tools_9.c \
		./mandatory/ft_putnbr.c ./mandatory/ft_putstr.c
		
OBJ1 = $(SRC1:.c=.o)

SRC2 = ./bonus/so_long_bonus.c ./bonus/ft_tools_bonus_1.c ./bonus/ft_tools_bonus_2.c \
		./bonus/ft_tools_bonus_3.c ./bonus/get_next_line.c ./bonus/get_next_line_utils.c ./bonus/ft_split.c \
		./bonus/ft_itoa.c ./bonus/valid_path_bonus_.c ./bonus/ft_tools_bonus_4.c \
		./bonus/ft_tools_bonus_5.c ./bonus/ft_tools_bonus_6.c ./bonus/ft_tools_bonus_7.c ./bonus/ft_tools_bonus_8.c \
		./bonus/ft_tools_bonus_9.c ./bonus/ft_tools_bonus_10.c ./bonus/ft_tools_bonus_11.c ./bonus/ft_putstr.c 
		
OBJ2 = $(SRC2:.c=.o)

NAME = so_long
NAMEB = so_long_bonus

HD1 = ./mandatory/so_long.h 
HD2 = ./bonus/so_long_bonus.h

all : $(NAME)
	
$(NAME) : $(OBJ1)
	$(CC) $(OBJ1) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(NAMEB)

$(NAMEB) : $(OBJ2)
	$(CC) $(OBJ2) -lmlx -framework OpenGL -framework AppKit -o $(NAMEB)

%.o : %.c $(HD1) $(HD2)
	$(CC) -Wall -Werror -Wextra -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ1) $(OBJ2)

fclean : clean
	rm -rf $(NAME) $(NAMEB)

re : fclean all