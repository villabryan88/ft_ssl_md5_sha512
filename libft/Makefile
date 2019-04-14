# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bvilla <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/22 20:11:16 by bvilla            #+#    #+#              #
#    Updated: 2019/03/05 23:59:57 by bvilla           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SOURCE = ft_memset.c ft_putchar.c ft_putnbr.c ft_putstr.c \
	 	 ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
		 ft_memchr.c ft_memcmp.c ft_strlen.c ft_strdup.c \
		 ft_strcpy.c ft_strncpy.c ft_strcat.c ft_strncat.c \
		 ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
		 ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c \
		 ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		 ft_isascii.c ft_isprint.c ft_toupper.c \
		 ft_tolower.c ft_memalloc.c ft_memdel.c \
		 ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c \
		 ft_striteri.c ft_strmap.c ft_strmapi.c \
		 ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c \
		 ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putendl.c \
		 ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		 ft_putnbr_fd.c ft_strnlen.c ft_isspace.c \
		 ft_wrdcnt.c ft_putnbrendl.c ft_iseven.c \
		 ft_isneg.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
		 ft_lstadd.c ft_lstiter.c ft_lstmap.c \
		 ft_splitstr.c ft_strtoupper.c ft_strjoin_free.c \
		 ft_arrlen.c ft_strisnum.c ft_strisint.c \
		 ft_elemval.c ft_lstsearch.c get_next_line.c \
		 ft_strarrdel.c ft_lstdelnode.c

PRINTF_FILES = ft_printf.c ft_itoa_base.c get_args.c is_cond.c str_manip.c floats.c \
		 dioux.c str_math.c format_float.c flip_flags.c 

PRINTF_PATH = printf
PRINTF_SOURCE = $(PRINTF_FILES:%=$(PRINTF_PATH)/%)

HEADERS = .
OBJS = $(SOURCE:%.c=%.o) $(PRINTF_FILES:%.c=%.o)

$(NAME): 
	@echo "compiling library"
	@gcc -g -Wall -Wextra -Werror -c $(SOURCE) $(PRINTF_SOURCE) -I $(HEADERS) 
	@ar rc $(NAME) $(OBJS) $
	@ranlib $(NAME)
clean:
	@rm -f $(OBJS)
	@echo "cleaned objects"
fclean: clean
	@rm -f $(NAME)
all: $(NAME)
re: fclean all

