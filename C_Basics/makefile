compileType_gcc=gcc
compileType_gpp=g++
compile_CommonQuery=-g -o

all:test1

test1:test1.c _lppublic.h _lppublic.c
	${compileType_gcc} ${compile_CommonQuery} test1 test1.c _lppublic.c

clean:
	rm -f test1
