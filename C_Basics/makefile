compileType_gcc=gcc
compileType_gpp=g++
compile_CommonQuery=-g -o

all:test1 testcpp testoverload testvector

test1:test1.c _lppublic.h _lppublic.c
	${compileType_gcc} ${compile_CommonQuery} test1 test1.c _lppublic.c

testcpp:testcpp.cpp
	${compileType_gpp} ${compile_CommonQuery} testcpp testcpp.cpp

testoverload:testoverload.cpp
	${compileType_gpp} ${compile_CommonQuery} testoverload testoverload.cpp

testvector:testvector.cpp
	${compileType_gpp} ${compile_CommonQuery} testvector testvector.cpp
clean:
	rm -f test1
	rm -f testcpp
	rm -f testoverload
	rm -f testvector
