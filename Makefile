batalha = ./bin/batalha

CC = g++

CPPFLAGS = -Wall -pedantic -ansi -std=c++11

OBJS = ./build/main.o ./build/monstro.o ./build/batalha.o ./build/IA.o ./build/fileHandler.o

batalha: $(batalha)

$(batalha): CPPFLAGS += -I. -I./include/
$(batalha): $(OBJS)
	$(CC) $^ $(CPPFLAGS) -o $@

./build/main.o: ./src/main.cpp ./include/fileHandler.h
	$(CC) -c $(CPPFLAGS) $<	-o $@

./build/monstro.o: ./src/monstro.cpp ./include/monstro.h ./include/acoes.h
	$(CC) -c $(CPPFLAGS) $<	-o $@	

./build/batalha.o: ./src/batalha.cpp ./include/batalha.h ./include/acoes.h
	$(CC) -c $(CPPFLAGS) $<	-o $@	

./build/IA.o: ./src/IA.cpp ./include/IA.h
	$(CC) -c $(CPPFLAGS) $<	-o $@	

./build/fileHandler.o: ./src/fileHandler.cpp ./include/fileHandler.h
	$(CC) -c $(CPPFLAGS) $<	-o $@	



dir:
	mkdir -p bin
	mkdir -p build
	mkdir -p data
	mkdir -p include
	mkdir -p src
	mkdir -p doc
	mkdir -p lib
	mkdir -p test
	
	
