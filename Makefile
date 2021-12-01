NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
PATH_MLX = mlx
LIBS = -Lminilibx -lmlx -lm -lz -framework OpenGL -framework AppKit -Lmylib -lmylib

HDIR = $(realpath headers)
ODIR = $(realpath objects)
SDIR = $(realpath sources)
MLX_PATH = $(realpath ./minilibx)
MYLIB = $(realpath ./mylib)
INCLUDES = -I$(HDIR) -I$(MLX_PATH) -I$(MYLIB) -I/usr/include

DESTROY_DIR = $(ODIR)/destroy
DESTROY_SRC = destroy.c
DESTROY_PATH = $(foreach file,$(DESTROY_SRC),$(DESTROY_DIR)/$(file))

DRAW_DIR = $(ODIR)/draw
DRAW_SRC = draw.c
DRAW_PATH = $(foreach file,$(DRAW_SRC),$(DRAW_DIR)/$(file))

INIT_DIR = $(ODIR)/initialize
INIT_SRC = hook.c initialize.c parsing.c
INIT_PATH = $(foreach file,$(INIT_SRC),$(INIT_DIR)/$(file))

RAY_DIR = $(ODIR)/ray_casting_logic
RAY_SRC = floor_casting.c sprite_casting.c wall_casting.c
RAY_PATH = $(foreach file,$(RAY_SRC),$(RAY_DIR)/$(file))

UPDATE_DIR = $(ODIR)/updating_functions
UPDATE_SRC = update.c
UPDATE_PATH = $(foreach file,$(UPDATE_SRC),$(UPDATE_DIR)/$(file))

UTILS_DIR = $(ODIR)/utils
UTILS_SRC = image_manipulation.c utils.c
UTILS_PATH = $(foreach file,$(UTILS_SRC),$(UTILS_DIR)/$(file))

MAIN_DIR = $(ODIR)
MAIN_SRC = main.c debugging.c
MAIN_PATH = $(foreach file,$(MAIN_SRC),$(MAIN_DIR)/$(file))

TARGETS = 	$(DESTROY_PATH:.c=.o) $(DRAW_PATH:.c=.o) $(INIT_PATH:.c=.o) $(RAY_PATH:.c=.o) $(UPDATE_PATH:.c=.o) \
			$(UTILS_PATH:.c=.o) $(MAIN_PATH:.c=.o)

DEPENDS:
	@$(MAKE) --directory=$(MYLIB)
	make $(NAME)
$(NAME): $(TARGETS)
	$(CC) -o $@ $^ $(LIBS)
$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/%.h $(HDIR)/definitions.h $(HDIR)/debugging.h
	cd $(dir $@) && $(CC) $(INCLUDES) $(CFLAGS) -c $<

.PHONY: all clean fclean re bonus fcleanall
all:
	make $(NAME)
clean:
	find $(ODIR) -type f ! -iname ".gitkeep" -delete
fclean:
	make clean
	rm -f $(NAME)
re:
	make clean
	make all
bonus: clean
bonus: $(MAKE) --directory=$(MYLIB)
bonus: CFLAGS += -D BONUS
bonus: $(NAME)
fcleanall:
	make fclean
	$(MAKE) fcleanall --directory=$(MYLIB)
