UTIL=item.c pilha.c util.c
MAIN=main.c
BINARY=executavel
ZIP=PilhaDeCartas.zip

all:
	gcc -Wall -Werror -g $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY)

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY)

zip:
	@zip -r $(ZIP) .