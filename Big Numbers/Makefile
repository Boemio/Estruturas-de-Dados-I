UTIL=item.c lista.c util.c
MAIN=main.c
BINARY=executavel
ZIP=bignumbers.zip

all:
	gcc -Wall -Werror -g $(UTIL) $(MAIN) -o $(BINARY)

run:
	./$(BINARY) 

valgrind:
	valgrind --tool=memcheck --leak-check=full  --track-origins=yes --show-leak-kinds=all --show-reachable=yes ./$(BINARY) < 1.in

zip:
	@zip -r $(ZIP) .