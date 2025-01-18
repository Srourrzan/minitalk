# -*- MakeFile -*-

SERVER_TARGET = server
CLIENT_TARGET = client
SERVER_SRCS = server.c
CLIENT_SRCS = client.c

OBJ_DIR = obj
SERVER_OBJS = $(addprefix $(OBJ_DIR)/, $(SERVER_SRCS:.c=.o))
CLIENT_OBJS = $(addprefix $(OBJ_DIR)/, $(CLIENT_SRCS:.c=.o))

CC = cc
CFLAGS = -Wall -Wextra -Werror -g

all: $(SERVER_TARGET) $(CLIENT_TARGET)

# Server target rule
$(SERVER_TARGET): $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(SERVER_OBJS) -o $(SERVER_TARGET)

# Client target rule
$(CLIENT_TARGET): $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(CLIENT_OBJS) -o $(CLIENT_TARGET)

# Pattern rule for compiling .o files in the obj directory
$(OBJ_DIR)/%.o: %.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to create the obj directory
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Clean and rebuild
re: fclean all

# Remove executables and object files
fclean: clean
	rm -f $(SERVER_TARGET) $(CLIENT_TARGET)

# Remove object files and obj directory
clean:
	rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	rm -rf $(OBJ_DIR)

# Mark these as phony targets
.PHONY: all clean fclean re