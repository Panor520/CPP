

compiletype=g++
compiletype1=gcc
debugtype=-g -o

all:seqlist linklist listarray liststack linkstack recursion listqueue linkqueue \
linkbinarytree matrixgraph listgraph 

#顺序表
seqlist:Seqlist.cpp
		${compiletype} ${debugtype} seqlist Seqlist.cpp

linklist:linklist.cpp
		${compiletype} ${debugtype} linklist linklist.cpp
		
listarray:listarray.cpp
		${compiletype} ${debugtype} listarray listarray.cpp

liststack:liststack.cpp
		${compiletype} ${debugtype} liststack liststack.cpp

linkstack:linkstack.cpp
		${compiletype} ${debugtype} linkstack linkstack.cpp

recursion:recursion.cpp
	${compiletype} ${debugtype} recursion recursion.cpp

listqueue:listqueue.cpp
	${compiletype} ${debugtype} listqueue listqueue.cpp

linkqueue:linkqueue.c
	 ${compiletype1} ${debugtype} linkqueue linkqueue.c

linkbinarytree:linkbinarytree.c
	${compiletype1} ${debugtype} linkbinarytree linkbinarytree.c

matrixgraph:matrixgraph.c
	${compiletype1} ${debugtype}  matrixgraph  matrixgraph.c

listgraph:listgraph.c
	${compiletype1} ${debugtype} listgraph listgraph.c

clean:
	rm -f seqlist
	rm -f linklist
	rm -f listarray
	rm -f liststack
	rm -f linkstack
	rm -f recursion
	rm -f listqueue
	rm -f linkqueue
	rm -f linkbinarytree
	rm -f matrixgraph
	rm -f listgraph
