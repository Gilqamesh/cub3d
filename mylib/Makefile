# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edavid <edavid@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/15 10:05:25 by edavid            #+#    #+#              #
#    Updated: 2021/11/26 20:20:40 by edavid           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
CTYPE_DIR = ctype
CTYPE_SRC = ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
			ft_tolower.c ft_toupper.c
CTYPE_H = $(HDIR)/ft_libftctype.h
EXTRA_DIR = extra
EXTRA_SRC = ft_get_ptr.c
EXTRA_H = $(HDIR)/ft_libftextra.h
GNL_DIR = gnl
GNL_SRC = get_next_line_utils.c get_next_line.c
GNL_H = $(HDIR)/ft_libftgnl.h
LIST_DIR = list
DLIST_DIR = $(LIST_DIR)/dlist
DLIST_SRC = ft_dlistadd_back.c ft_dlistadd_front.c ft_dlistclear.c ft_dlistdel.c \
			ft_dlistdelone.c ft_dlistiter.c ft_dlistlast.c ft_dlistmap.c ft_dlistnew.c \
			ft_dlistprint_int.c ft_dlistsize.c ft_dlistsortedinsert_int.c \
			ft_dliststr_to_strarr.c ft_dliststrarrjoin_from_back.c ft_dliststrjoin_from_back.c
DLIST_H = $(HDIR)/ft_libftdlist.h
FILELIST_DIR = $(LIST_DIR)/filelist
FILELIST_SRC =	ft_filelistadd_back.c ft_filelistclear.c ft_filelistdel.c ft_filelistdelone.c \
				ft_filelistnew.c
FILELIST_H = $(HDIR)/ft_libftfilelist.h
OBJLIST_DIR = $(LIST_DIR)/objlist
OBJLIST_SRC = 	ft_objlst_clear.c ft_objlst_del.c ft_objlst_delone.c ft_objlst_findbykey.c \
				ft_objlst_mapFromEnv.c ft_objlst_new.c ft_objlst_rem.c ft_objlstadd_front.c \
				ft_objlstinsert.c
OBJLIST_H = $(HDIR)/ft_libftobjlist.h
SLIST_DIR = $(LIST_DIR)/slist
SLIST_SRC = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdel.c ft_lstdelone.c \
			ft_lstiter.c ft_lstlast.c ft_lstmallocfree.c ft_lstmallocwrapper.c ft_lstmap.c \
			ft_lstnew.c ft_lstprint_int.c ft_lstsize.c ft_lstsortedinsert_int.c
SLIST_H = $(HDIR)/ft_libftslist.h
MATH_DIR = math
MATH_SRC = 	ft_abs_int.c ft_baselen.c ft_intlen.c ft_maxofint.c ft_minofint.c ft_fabs.c \
		ft_round_to_nearest_int.c
MATH_H = $(HDIR)/ft_libftmath.h
MEMORY_DIR = memory
MEMORY_SRC = 	ft_bzero.c ft_calloc.c ft_intdup.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
				ft_memcpy.c ft_memmove.c ft_memset.c
MEMORY_H = $(HDIR)/ft_libftmemory.h
PRINT_DIR = print
PRINT_SRC = ft_printintarr.c
PRINT_H = $(HDIR)/ft_libftprint.h
PRINTF_DIR = $(PRINT_DIR)/printf
PRINTF_SRC = 	ft_conversion_router.c ft_print_character.c ft_print_hexa.c ft_print_integer.c \
				ft_print_percent.c ft_print_pointer.c ft_print_string.c ft_print_unsigned.c \
				ft_printf.c ft_set_flags.c
PRINTF_H = $(HDIR)/ft_libftprint.h
PUT_DIR = put
PUT_SRC = ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putnstr_fd.c ft_putstr_fd.c
PUT_H = $(HDIR)/ft_libftput.h
SORT_DIR = sort
SORT_SRC = ft_merge_sort_int.c ft_merge_sort_str.c
SORT_H = $(HDIR)/ft_libftsort.h
STRING_DIR = string
STRING_SRC = 	ft_atoi.c ft_destroy_str_arr.c ft_isStrAlphaNumeric.c ft_isStrContainedInStrArr.c \
				ft_isStrNumber.c ft_itoa.c ft_itobase.c ft_n_of_words_by_delim.c ft_split.c \
				ft_splitstr.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strdupchr.c ft_strjoin.c \
				ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strToStrArr.c ft_strtrim.c ft_substr.c ft_trim_from_left_index.c \
				ft_trim_from_right_index.c ft_strjoin_free.c
STRING_H = $(HDIR)/ft_libftstring.h
VALIDIFIERS_DIR = validifiers
VALIDIFIERS_SRC = ft_isValidBashIdentifier.c ft_isValidCName.c
VALIDIFIERS_H = $(HDIR)/ft_libftvalid.h
HDIR = headers
ODIR = objects
CTYPE_PATH =		$(foreach file,$(CTYPE_SRC),$(CTYPE_DIR)/$(file))
EXTRA_PATH =		$(foreach file,$(EXTRA_SRC),$(EXTRA_DIR)/$(file))
GNL_PATH =			$(foreach file,$(GNL_SRC),$(GNL_DIR)/$(file))
DLIST_PATH =		$(foreach file,$(DLIST_SRC),$(DLIST_DIR)/$(file))
FILELIST_PATH =		$(foreach file,$(FILELIST_SRC),$(FILELIST_DIR)/$(file))
OBJLIST_PATH =		$(foreach file,$(OBJLIST_SRC),$(OBJLIST_DIR)/$(file))
SLIST_PATH =		$(foreach file,$(SLIST_SRC),$(SLIST_DIR)/$(file))
MATH_PATH =			$(foreach file,$(MATH_SRC),$(MATH_DIR)/$(file))
MEMORY_PATH =		$(foreach file,$(MEMORY_SRC),$(MEMORY_DIR)/$(file))
PRINT_PATH =		$(foreach file,$(PRINT_SRC),$(PRINT_DIR)/$(file))
PRINTF_PATH =		$(foreach file,$(PRINTF_SRC),$(PRINTF_DIR)/$(file))
PUT_PATH =			$(foreach file,$(PUT_SRC),$(PUT_DIR)/$(file))
SORT_PATH =			$(foreach file,$(SORT_SRC),$(SORT_DIR)/$(file))
STRING_PATH =		$(foreach file,$(STRING_SRC),$(STRING_DIR)/$(file))
VALIDIFIERS_PATH =	$(foreach file,$(VALIDIFIERS_SRC),$(VALIDIFIERS_DIR)/$(file))
SRC =	$(CTYPE_PATH) $(EXTRA_PATH) $(GNL_PATH) $(DLIST_PATH) $(FILELIST_PATH) $(OBJLIST_PATH) \
		$(SLIST_PATH) $(MATH_PATH) $(MEMORY_PATH) $(PRINT_PATH) $(PRINTF_PATH) $(PUT_PATH) \
		$(SORT_PATH) $(STRING_PATH) $(VALIDIFIERS_PATH)
INCLUDES = ../../$(HDIR)
NAME = libft.a

$(NAME): $(foreach file,$(SRC:.c=.o),$(ODIR)/$(file))
	ar -rs $(NAME) $?
$(ODIR)/$(CTYPE_DIR)/%.o: $(CTYPE_DIR)/%.c $(CTYPE_H)
	cd $(ODIR)/$(CTYPE_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(EXTRA_DIR)/%.o: $(EXTRA_DIR)/%.c $(EXTRA_H)
	cd $(ODIR)/$(EXTRA_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(GNL_DIR)/%.o: $(GNL_DIR)/%.c $(GNL_H)
	cd $(ODIR)/$(GNL_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(DLIST_DIR)/%.o: $(DLIST_DIR)/%.c $(DLIST_H)
	cd $(ODIR)/$(DLIST_DIR) && $(CC) -I../$(INCLUDES) $(CFLAGS) -c ../../../$<
$(ODIR)/$(FILELIST_DIR)/%.o: $(FILELIST_DIR)/%.c $(FILELIST_H)
	cd $(ODIR)/$(FILELIST_DIR) && $(CC) -I../$(INCLUDES) $(CFLAGS) -c ../../../$<
$(ODIR)/$(OBJLIST_DIR)/%.o: $(OBJLIST_DIR)/%.c $(OBJLIST_H)
	cd $(ODIR)/$(OBJLIST_DIR) && $(CC) -I../$(INCLUDES) $(CFLAGS) -c ../../../$<
$(ODIR)/$(SLIST_DIR)/%.o: $(SLIST_DIR)/%.c $(SLIST_H)
	cd $(ODIR)/$(SLIST_DIR) && $(CC) -I../$(INCLUDES) $(CFLAGS) -c ../../../$<
$(ODIR)/$(MATH_DIR)/%.o: $(MATH_DIR)/%.c $(MATH_H)
	cd $(ODIR)/$(MATH_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(MEMORY_DIR)/%.o: $(MEMORY_DIR)/%.c $(MEMORY_H)
	cd $(ODIR)/$(MEMORY_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(PRINTF_DIR)/%.o: $(PRINTF_DIR)/%.c $(PRINTF_H)
	cd $(ODIR)/$(PRINTF_DIR) && $(CC) -I../$(INCLUDES) $(CFLAGS) -c ../../../$<
$(ODIR)/$(PRINT_DIR)/%.o: $(PRINT_DIR)/%.c $(PRINT_H)
	cd $(ODIR)/$(PRINT_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(PUT_DIR)/%.o: $(PUT_DIR)/%.c $(PUT_H)
	cd $(ODIR)/$(PUT_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(SORT_DIR)/%.o: $(SORT_DIR)/%.c $(SORT_H)
	cd $(ODIR)/$(SORT_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(STRING_DIR)/%.o: $(STRING_DIR)/%.c $(STRING_H)
	cd $(ODIR)/$(STRING_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
$(ODIR)/$(VALIDIFIERS_DIR)/%.o: $(VALIDIFIERS_DIR)/%.c $(VALIDIFIERS_H)
	cd $(ODIR)/$(VALIDIFIERS_DIR) && $(CC) -I$(INCLUDES) $(CFLAGS) -c ../../$<
.PHONY: clean all fclean re fcleanall
all: $(NAME)
clean:
	rm -f __.SYMDEF __.SYMDEF\ SORTED
	rm -f $(ODIR)/$(CTYPE_DIR)/*.o
	rm -f $(ODIR)/$(EXTRA_DIR)/*.o
	rm -f $(ODIR)/$(DLIST_DIR)/*.o
	rm -f $(ODIR)/$(FILELIST_DIR)/*.o
	rm -f $(ODIR)/$(OBJLIST_DIR)/*.o
	rm -f $(ODIR)/$(SLIST_DIR)/*.o
	rm -f $(ODIR)/$(MATH_DIR)/*.o
	rm -f $(ODIR)/$(MEMORY_DIR)/*.o
	rm -f $(ODIR)/$(PRINT_DIR)/*.o
	rm -f $(ODIR)/$(PRINTF_DIR)/*.o
	rm -f $(ODIR)/$(PUT_DIR)/*.o
	rm -f $(ODIR)/$(SORT_DIR)/*.o
	rm -f $(ODIR)/$(STRING_DIR)/*.o
	rm -f $(ODIR)/$(VALIDIFIERS_DIR)/*.o
fclean:
	make clean
	rm -f $(NAME)
re:
	make fclean
	make all
fcleanall: fclean
