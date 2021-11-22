# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edavid <edavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/25 20:47:25 by edavid            #+#    #+#              #
#    Updated: 2021/09/22 19:03:34 by edavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a
LIBFT = ../libft/libft.a
sources = ft_printf.c ft_conversions.c ft_conversions2.c \
ft_conversions_utils.c ft_conversions_utils2.c ft_printf_utils.c \
ft_set_flags.c ft_print_conversion_hexa.c ft_print_conversion_hexa_utilities.c \
ft_print_conversion_s_utilities.c ft_print_conversion_s.c ft_print_conversion_p.c \
ft_print_conversion_int.c ft_print_conversion_int_utils.c ft_print_conversion_uint.c \
ft_print_conversion_uint_utils.c ft_printf_utils2.c ft_print_conversion_s_utilities2.c \
ft_print_conversion_int_utils2.c

Dependencies: $(LIBFT)
	$(MAKE) $(NAME)
$(NAME): $(sources:.c=.o)
	cp $(LIBFT) .
	mv libft.a $(NAME)
	ar -rs $(NAME) $?
%.o: %.c $(LIBFT)
	$(CC) $(CFLAGS) -c $<
$(LIBFT): ../libft/*.c ../libft/*.h
	$(MAKE) --directory=../libft
.PHONY: all clean fclean re bonus fcleanall
all: $(NAME)
clean:
	rm -f *.o libft/*.o __.SYMDEF __.SYMDEF\ SORTED
fclean: clean
	rm -f $(NAME)
re:
	make clean
	make all
bonus: all
fcleanall: fclean
