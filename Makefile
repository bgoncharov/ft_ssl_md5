# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bogoncha <bogoncha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/22 18:49:15 by bogoncha          #+#    #+#              #
#    Updated: 2019/07/29 19:54:36 by bogoncha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl

FLAGS = -Wall -Werror -Wextra

SRC = ft_ssl.c parser.c func_md5.c md5_stages.c md5.c sha.c sha_init.c func_sha.c ft_sha512.c ft_sha256.c put_hash.c

all: $(NAME)

$(NAME):
	@make -C ft_printf
	@gcc  $(FLAGS) -o $(NAME) $(SRC) ft_printf/libftprintf.a

clean:
	@make -C ft_printf/ clean
	@rm -f $(SRC:.c=.o)

fclean: clean
	@make -C ft_printf/ fclean
	@rm -f $(NAME)

re: fclean all