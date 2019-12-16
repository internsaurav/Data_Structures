CC = g++
CFLAGS  = -g -Wall
I1 = -I ../../IOutils
I2 = -I ../Elementary_Structures/Tree_Node
RM = rm

default: bin_search_tree

bin_search_tree: bin_search_tree_implementor.o bin_search_tree.o treeUtils.o utils.o
	$(CC)  $(CFLAGS) -o bin_search_tree bin_search_tree_implementor.o bin_search_tree.o treeUtils.o utils.o

bin_search_tree_implementor.o: bin_search_tree_implementor.cpp bin_search_tree.h ../../IOutils/utils.h
	$(CC) $(I1) $(I2) $(CFLAGS) -c bin_search_tree_implementor.cpp

bin_search_tree.o: bin_search_tree.cpp bin_search_tree.h
	$(CC) $(I2) $(CFLAGS) -c bin_search_tree.cpp

treeUtils.o: ../../IOutils/treeUtils.cpp ../../IOutils/treeUtils.h
	$(CC) $(I1) $(I2) $(CFLAGS) -c ../../IOutils/treeUtils.cpp

utils.o: ../../IOutils/utils.cpp ../../IOutils/utils.h
	$(CC) $(I1) $(I2) $(CFLAGS) -c ../../IOutils/utils.cpp 

clean:
	$(RM) bin_search_tree *.o