CC=gcc
CLIENT=TCPClient
SERVER=TCPServer
FLAGS=-Wall -Werror
CLIENT_SRC=src_client/main.c
SERVER_SRC=src_server/main.c

all: client server
client: $(CLIENT)
server: $(SERVER)

$(CLIENT): $(CLIENT_SRC)
	$(CC) $^ -o $@ $(FLAGS)

$(SERVER): $(SERVER_SRC)
	$(CC) $^ -o $@ $(FLAGS)

clean:
	rm -rf $(CLIENT) $(SERVER)

.PHONY: all
