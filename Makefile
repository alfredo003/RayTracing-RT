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
		$(DIR_SRC)/scene/validate_scene.c

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
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(LIBX) -lm -o $(TARGET)

clean:
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(LIBX_DIR)
	$(RM) $(DIR_OBJ)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(DIR_BIN)

re: fclean all

