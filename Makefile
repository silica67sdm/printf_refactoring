# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sajeon <sajeon@student.42seoul.kr>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 14:27:57 by sajeon            #+#    #+#              #
#    Updated: 2021/02/26 22:35:20 by sajeon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = libftprintf.a

SRCS = ft_printf.c \
		flag_parse_util.c \
		global_util.c \
		print_char.c \
		print_int.c \
		print_unsigned_int.c \
		print_string.c \
		print_pointer.c \
		print_percent.c \
		print_hex.c

OBJS = $(SRCS:.c=.o)

INC = ft_printf.h

all : $(TARGET)

$(TARGET) : $(INC) $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $@
	gcc -c -Wall -Wextra -Werror $(INC) $(SRCS)
	ar rcs $@ $^

clean:
	$(MAKE) clean -C ./libft
	rm -rf ${OBJS}

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -rf $(TARGET)

re: fclean all

test: re
	gcc main_test.c -o main_test libftprintf.a
	./main_test

test_clean: fclean
	rm -rf main_test
	rm -rf ft_printf.h.gch
