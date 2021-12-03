NAME = cub3D
CC = gcc
CFLAGS = -Wall -Wextra -Werror -O3
PATH_MLX = mlx
LIBS = 	-Lminilibx -lmlx -lm -lz -framework OpenGL -framework AppKit \
		-Lmylib -lmylib

HDIR = $(realpath headers)
ODIR = $(realpath objects)
SDIR = $(realpath sources)
MLX_PATH = $(realpath ./minilibx)
MYLIB = $(realpath ./mylib)
INCLUDES = -I$(HDIR) -I$(MLX_PATH) -I$(MYLIB) -I/usr/include

DESTROY_DIR = destroy
DESTROY_SRC = destroy.c
DESTROY_PATH = $(foreach file,$(DESTROY_SRC),$(ODIR)/$(DESTROY_DIR)/$(file))

DRAW_DIR = draw
DRAW_SRC = 	draw_textures.c draw_wall.c draw_sprite_stripe.c draw_utils.c \
			draw_line.c
DRAW_PATH = $(foreach file,$(DRAW_SRC),$(ODIR)/$(DRAW_DIR)/$(file))

INIT_DIR = initialize
INIT_SRC = 	hook.c initialize.c parsing_1.c parsing_2.c parsing_3.c \
			parsing_4.c parsing_5.c init_textures.c init_minimap.c \
			init_sprites.c key_hook.c init_wall_ray.c init_sprite_draw.c

INIT_PATH = $(foreach file,$(INIT_SRC),$(ODIR)/$(INIT_DIR)/$(file))

RAY_DIR = ray_casting_logic
RAY_SRC = floor_casting.c sprite_casting.c wall_casting.c
RAY_PATH = $(foreach file,$(RAY_SRC),$(ODIR)/$(RAY_DIR)/$(file))

UPDATE_DIR = updating_functions
UPDATE_SRC = update.c render_frame.c update_key.c update_key_movement.c
UPDATE_PATH = $(foreach file,$(UPDATE_SRC),$(ODIR)/$(UPDATE_DIR)/$(file))

UTILS_DIR = utils
UTILS_SRC = image_manipulation.c utils.c merge_sort_sprites.c
UTILS_PATH = $(foreach file,$(UTILS_SRC),$(ODIR)/$(UTILS_DIR)/$(file))

MAIN_SRC = main.c
MAIN_PATH = $(foreach file,$(MAIN_SRC),$(ODIR)/$(file))

TARGETS = 	$(DESTROY_PATH:.c=.o) $(DRAW_PATH:.c=.o) $(INIT_PATH:.c=.o) \
			$(RAY_PATH:.c=.o) $(UPDATE_PATH:.c=.o) $(UTILS_PATH:.c=.o) \
			$(MAIN_PATH:.c=.o)

DEPENDS:
	@$(MAKE) --directory=$(MYLIB)
	make $(NAME)
$(NAME): $(TARGETS)
	$(CC) -o $@ $^ $(LIBS)
$(ODIR)/%.o: 	$(SDIR)/%.c $(HDIR)/$(dir %)/*.h $(HDIR)/definitions.h
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
