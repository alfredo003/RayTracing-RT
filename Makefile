NAME = RayTracer
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc

RM = rm -rf

DIR_OBJ = obj
DIR_BIN = bin
DIR_SRC = src

LIBFT_DIR = ./libs/libft
LIBFT_INC = -I$(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

LIBX_DIR = ./libs/minilibx-linux
LIBX_INC = -I$(LIBX_DIR)
LIBX = $(LIBX_DIR)/libmlx_Linux.a

SRCS = $(DIR_SRC)/main.c \
		$(DIR_SRC)/init.c \
		$(DIR_SRC)/parse_scene/ambient_light.c \
		$(DIR_SRC)/parse_scene/camera.c \
		$(DIR_SRC)/parse_scene/direction.c \
		$(DIR_SRC)/parse_scene/position.c \
		$(DIR_SRC)/parse_scene/light.c \
		$(DIR_SRC)/parse_scene/sphere.c \
		$(DIR_SRC)/parse_scene/plane.c \
		$(DIR_SRC)/parse_scene/parse_scene_file.c \
		$(DIR_SRC)/parse_scene/utils.c\
		$(DIR_SRC)/parse_scene/color.c\
		$(DIR_SRC)/parse_scene/cylinder.c\
		$(DIR_SRC)/parse_scene/diameter_height.c\
		$(DIR_SRC)/parse_scene/axis.c\
		$(DIR_SRC)/win/render_scene.c \
		$(DIR_SRC)/win/raytracing.c \
		$(DIR_SRC)/win/events.c \
		$(DIR_SRC)/win/intersections/intersect_sphere.c \
		$(DIR_SRC)/win/intersections/intersect_plane.c \
		$(DIR_SRC)/win/intersections/intersect_cylinder.c \
		$(DIR_SRC)/win/shading/shade_cylinder.c \
		$(DIR_SRC)/win/shading/shade_plane.c \
		$(DIR_SRC)/win/shading/shade_sphere.c \
		$(DIR_SRC)/utils/vec3.c \
		$(DIR_SRC)/utils/list_objs.c

OBJS = $(SRCS:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

TARGET = $(DIR_BIN)/$(NAME)

all: $(TARGET)

$(DIR_OBJ)/%.o: $(DIR_SRC)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBFT_INC) $(LIBX_INC) -c $< -o $@

$(TARGET): $(OBJS)
	@make -C $(LIBFT_DIR)
	@make -C $(LIBX_DIR)
	mkdir -p $(DIR_BIN)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBX)  -lX11 -lXext -lm -lz -o $(TARGET)
	@clear
clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBX_DIR)
	$(RM) $(DIR_OBJ)
	@clear

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(DIR_BIN)
	@clear

re: fclean all

