# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edavid <edavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 10:05:25 by edavid            #+#    #+#              #
#    Updated: 2021/09/18 20:13:08 by edavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
sources = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c \
ft_memchr.c ft_memcmp.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strchr.c \
ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isdigit.c ft_isalpha.c \
ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
bonus_sources = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
extended_sources = ft_nodbinadd_back.c ft_nodbinadd_front.c \
ft_nodbinclear.c ft_nodbindelone.c ft_nodbiniter.c ft_nodbinlast.c \
ft_nodbinmap.c ft_nodbinnew.c ft_nodbinsize.c ft_nodbindel.c ft_nodbinprint_int.c \
ft_lstsortedinsert_int.c ft_lstdel.c ft_lstprint_int.c ft_merge_sort_int.c \
ft_abs_int.c ft_merge_sort_str.c ft_strcmp.c ft_intdup.c ft_printintarr.c \
ft_intlen.c ft_minofint.c ft_putnstr_fd.c ft_maxofint.c ft_baselen.c ft_itobase.c \
ft_n_of_words_by_delim.c ft_destroy_str_arr.c ft_nodbinstrjoin_from_back.c \
ft_lstmallocwrapper.c ft_lstmallocfree.c ft_splitstr.c ft_nodbinstrarrjoin_from_back.c \
ft_nodbinstr_to_strarr.c ft_trim_from_left_index.c ft_isStrAlphaNumeric.c \
ft_isValidCName.c ft_isValidBashIdentifier.c ft_isStrContainedInStrArr.c \
ft_objlst_findbykey.c ft_objlstadd_front.c ft_strdupchr.c ft_objlst_new.c \
ft_objlst_mapFromEnv.c ft_objlst_clear.c ft_objlst_delone.c ft_objlst_del.c \
ft_filelstadd_back.c ft_filelstclear.c ft_filelstdel.c ft_filelstdelone.c \
ft_filelstnew.c ft_objlst_rem.c ft_strToStrArr.c ft_trim_from_right_index.c \
ft_objlstinsert.c ft_isStrNumber.c ft_nodbinsortedinsert_int.c ft_get_ptr.c
NAME = libft.a


$(NAME) : $(sources:.c=.o) $(bonus_sources:.c=.o) $(extended_sources:.c=.o)
	ar -rs $(NAME) $?
%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $<
.PHONY: clean bonus all fclean re fcleanall
all: $(NAME) bonus
clean:
	rm -f *.o __.SYMDEF __.SYMDEF\ SORTED
bonus: $(bonus_sources:.c=.o) $(extended_sources:.c=.o)
	ar -rs $(NAME) $?
fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all
fcleanall: fclean
