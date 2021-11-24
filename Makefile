NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
PATH_MLX = mlx
LIBS = -L/usr/lib -lXext -lX11 -Lmlx_linux -lmlx -lm -lz
SRC = main.c initialize.c utils.c hook.c
HDIR = headers
ODIR = objects
SDIR = sources
MYLIB = mylib/libmylib.a
INCLUDES = -I../$(HDIR) -I../mlx_linux -I../mylib -I/usr/include

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
