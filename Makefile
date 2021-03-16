SRC = main.c BST.c
OBJ = main.o BST.o 
PROG = wordfreak

$(PROG): $(OBJ)
	gcc $(OBJ) -o $(PROG)

$(OBJ): $(SRC)