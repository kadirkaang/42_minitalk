SERVER	= server
CLIENT	= client

CFLAGS	= -Wall -Werror -Wextra
CC		= gcc
INC		= -I minitalk.h $(PRINTF_DIR)/libftprintf.a
MAKE	= make

PRINTF_DIR	= ft_printf

all:
	$(MAKE) -s -C $(PRINTF_DIR)
	$(CC) $(FLAGS) server.c $(INC) -o $(SERVER)
	$(CC) $(FLAGS) client.c $(INC) -o $(CLIENT)

clean:
	$(MAKE) clean -s -C $(PRINTF_DIR)

fclean: clean
	$(MAKE) fclean -s -C $(PRINTF_DIR)
	rm -rf $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re