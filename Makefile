NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
PATH_MLX = mlx
LIBS = -Lminilibx -lmlx -lm -lz -framework OpenGL -framework AppKit -Lmylib -lmylib
SRC = 	main.c initialize.c utils.c hook.c destroy.c parsing.c wall_casting.c \
		floor_casting.c image_manipulation.c update.c draw.c sprite_casting.c
SRC += debugging.c
HDIR = $(realpath headers)
ODIR = $(realpath objects)
SDIR = $(realpath sources)
MLX_PATH = $(realpath ./minilibx)
MYLIB = $(realpath ./mylib)
INCLUDES = -I$(HDIR) -I$(MLX_PATH) -I$(MYLIB) -I/usr/include
SRC_DIRS = destroy draw initialize ray_casting_logic updating_functions utils
TARGETS = $(foreach target,$(foreach dir,$(SRC_DIRS),$(ODIR)/$(dir)),$(target)/*.o)

DEPENDS:
	$(MAKE) --directory=$(MYLIB)
	make $(NAME)
$(NAME): $(TARGETS)
	$(CC) -o $@ $^ $(LIBS)
$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/%.h
	cd $(dir $@) && $(CC) $(INCLUDES) $(CFLAGS) -c $<

.PHONY: all clean fclean re bonus fcleanall
all:
	make $(NAME)
clean:
	rm -rf $(find $(ODIR)/*.o)
fclean:
	make clean
	rm -f $(NAME)
re:
	make clean
	make all
bonus: clean
bonus: CFLAGS += -D BONUS
bonus: $(NAME)
fcleanall:
	make fclean
	$(MAKE) fcleanall --directory=$(MYLIB)
