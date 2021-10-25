# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sungwopa <sungwopa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 23:34:39 by sungwopa          #+#    #+#              #
#    Updated: 2021/10/26 07:05:46 by sungwopa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET1 = server

TARGET2 = client

all :
		make -C libft
		gcc -Wall -Wextra -Werror server.c libft/libft.a -o $(TARGET1)
		gcc -Wall -Wextra -Werror client.c libft/libft.a -o $(TARGET2)

clean :
		make clean -C libft
		rm -rf client.o server.o

fclean : clean
		make fclean -C libft
		rm -rf $(TARGET1) $(TARGET2)

re : fclean all
