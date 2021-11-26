NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
PATH_MLX = mlx
LIBS = -Lminilibx -lmlx -lm -lz -framework OpenGL -framework AppKit -Lmylib -lmylib
SRC = main.c initialize.c utils.c hook.c destroy.c
HDIR = headers
ODIR = objects
SDIR = sources
MYLIB = mylib/libmylib.a
INCLUDES = -I../$(HDIR) -I../minilibx -I../mylib -I/usr/include

DEPENDS: $(MYLIB)
	make $(NAME)
$(NAME): $(foreach file,$(SRC:.c=.o),$(ODIR)/$(file))
	$(CC) -o $@ $^ $(LIBS)
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
