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
		$(DIR_SRC)/scene/ambient_light.c \
		$(DIR_SRC)/scene/camera.c \
		$(DIR_SRC)/scene/direction.c \
		$(DIR_SRC)/scene/position.c \
		$(DIR_SRC)/scene/validate.c \
		$(DIR_SRC)/scene/utils.c\
		$(DIR_SRC)/scene/color.c\
		$(DIR_SRC)/win/render_scene.c \
		$(DIR_SRC)/win/events.c \
		$(DIR_SRC)/utils/vec3.c

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
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBX)  -lX11 -lXext -lm -o $(TARGET)
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

