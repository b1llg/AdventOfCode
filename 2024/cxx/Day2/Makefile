CXX=g++
CXX_FLAGS= -g -Wall -Wextra
EXE=main

all:
	${CXX} ${CXX_FLAGS} ${EXE}.cpp -o ${EXE} 

dbg:
	gdb --args ./${EXE} --tui=enable