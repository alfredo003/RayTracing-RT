NAME = RayTracer
CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinc
RM = rm -rf

DIR_OBJ = obj
DIR_BIN = bin
DIR_SRC = src

LIBFT_DIR = ./libs/libft
LIBFT_INC = -I  $(LIBFT_DIR)
LIBFT = $(LIBFT_DIR)/libft.a

SRCS = $(DIR_SRC)/main.c

OBJS = $(SRCS:$(DIR_SRC)/%.c=$(DIR_OBJ)/%.o)

TARGET = $(DIR_BIN)/$(NAME)

all: $(TARGET)


$(DIR_OBJ)/%.o:$(DIR_SRC)/%.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(LIBFT_INC) -c $< -o $@
	@clear 

$(TARGET): $(OBJS) 
	@make -C  $(LIBFT_DIR)
	mkdir -p $(DIR_BIN) 
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(TARGET)
	@clear

clean: 
	@make clean -C $(LIBFT_DIR)
	$(RM) $(DIR_OBJ)
	@clear
	
fclean: clean
	@make fclean -C $(LIBFT_DIR)
	$(RM) $(DIR_BIN)
	@clear

re: fclean all


