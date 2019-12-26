CC = g++
CFLAGS  = -g -Wall
I1 = -I ../../IOutils
I2 = -I ../Elementary_Structures/Tree_Node
I3 = -I ../../Algorithms/Graph_Traversals/
RM = rm

default: bin_search_tree

bin_search_tree: bin_search_tree_implementor.o bin_search_tree.o breadth_first_search.o treeUtils.o utils.o
	$(CC)  $(CFLAGS) -o bin/bin_search_tree bin_search_tree_implementor.o bin_search_tree.o breadth_first_search.o treeUtils.o utils.o

bin_search_tree_implementor.o: bin_search_tree_implementor.cpp bin_search_tree.h ../../IOutils/utils.h ../../Algorithms/Graph_Traversals/breadth_first_search.h
	$(CC) $(I1) $(I2) $(I3) $(CFLAGS) -c bin_search_tree_implementor.cpp

bin_search_tree.o: bin_search_tree.cpp bin_search_tree.h
	$(CC) $(I2) $(CFLAGS) -c bin_search_tree.cpp

breadth_first_search.o: ../../Algorithms/Graph_Traversals/breadth_first_search.cpp ../../Algorithms/Graph_Traversals/breadth_first_search.h
	$(CC) $(I2) $(I3) $(CFLAGS) -c ../../Algorithms/Graph_Traversals/breadth_first_search.cpp

treeUtils.o: ../../IOutils/treeUtils.cpp ../../IOutils/treeUtils.h
	$(CC) $(I1) $(I2) $(CFLAGS) -c ../../IOutils/treeUtils.cpp

utils.o: ../../IOutils/utils.cpp ../../IOutils/utils.h
	$(CC) $(I1) $(I2) $(CFLAGS) -c ../../IOutils/utils.cpp 

clean:
	$(RM) bin/bin_search_tree *.o