NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
PATH_MLX = mlx
LIBS = -Lminilibx -lmlx -lm -lz -framework OpenGL -framework AppKit -Lmylib -lmylib
SRC = 	main.c initialize.c utils.c hook.c destroy.c parsing.c wall_casting.c \
		floor_casting.c image_manipulation.c update.c draw.c sprite_casting.c
SRC += debugging.c
HDIR = headers
ODIR = objects
SDIR = sources
INCLUDES = -I../$(HDIR) -I../minilibx -I../mylib -I/usr/include

DEPENDS:
	$(MAKE) --directory=mylib
	make $(NAME)
$(NAME): $(foreach file,$(SRC:.c=.o),$(ODIR)/$(file))
	$(CC) -o $@ $^ $(LIBS)
$(ODIR)/main.o: $(SDIR)/main.c
	cd $(ODIR) && $(CC) $(INCLUDES) $(CFLAGS) -c ../$<
$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/%.h
	cd $(ODIR) && $(CC) $(INCLUDES) $(CFLAGS) -c ../$<

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
