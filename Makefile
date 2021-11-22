NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBS = -Lminilibx -lmlx -lm -lz -framework OpenGL -framework AppKit
SRC = main.c
HDIR = headers
ODIR = objects
SDIR = sources
MYLIB = mylib/libmylib.a
INCLUDES = -I../$(HDIR) -I../minilibx -I../mylib

$(NAME): $(MYLIB) $(foreach file,$(SRC:.c=.o),$(ODIR)/$(file))
	$(CC) -o $@ $(LIBS) $^
$(ODIR)/main.o: $(SDIR)/main.c
	cd $(ODIR) && $(CC) $(INCLUDES) $(CFLAGS) -c ../$<
$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/%.h
	cd $(ODIR) && $(CC) $(INCLUDES) $(CFLAGS) -c ../$<
$(MYLIB):
	$(MAKE) --directory=mylib

.PHONY: all clean fclean re bonus fcleanall
all:
	make $(NAME)
clean:
	rm -f $(ODIR)/*.o
fclean:
	make clean
	rm -f $(NAME)
re:
	make clean
	make all
bonus:
	make $(NAME)
fcleanall:
	make fclean
	$(MAKE) fcleanall --directory=mylib
