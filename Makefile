# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 18:49:15 by bogoncha          #+#    #+#              #
#    Updated: 2019/07/23 15:46:07 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra

SRC = ft_ssl.c parser.c func_md5.c md5_stages.c md5.c sha.c

all: $(NAME)

$(NAME):
	@gcc  $(FLAGS) -o $(NAME) $(SRC) ft_printf/includes/libftprintf.a

clean:
	@rm -f $(SRC:.c=.o)

fclean: clean
	@rm -f $(NAME)

re: fclean all