CC = gcc
CFLAGS = -Wall -Werror -g
SRC = main.c db.c commands.c storage.c utils.c
OBJ = $(SRC:.c=.o)
EXEC = simple_db

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJ) $(EXEC)

# Commande pour exécuter les tests
test: $(EXEC)
	./$(EXEC) --test
