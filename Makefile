# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvilla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 20:11:16 by bvilla            #+#    #+#              #
#    Updated: 2019/04/15 16:46:04 by bvilla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ssl
SOURCE = md5.c sha256.c hash_generic_functions.c ft_ssl.c
INC = .
OBJS = $(SOURCE:%.c=%.o)

$(NAME): $(SOURCE)
	@make -C libft/ 
	@gcc -g -c -Wall -Wextra -Werror $(SOURCE) -I. -I libft/
	@gcc -g $(OBJS) -Wall -Wextra -Werror libft/libft.a -o $(NAME)
	@echo "compilation complete"
all: $(NAME)
clean:
	@rm -f $(OBJS) 
	@make clean -C libft/
	@echo "removed objects"
fclean: clean
	@rm -f $(NAME)
	@make fclean -C libft/
	@echo "removed binary and libraries"
re: fclean all 
