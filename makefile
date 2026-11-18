all: derle calistir

derle:
	g++ -I ./include/ -o ./lib/HucreDugum.o -c ./src/HucreDugum.cpp
	g++ -I ./include/ -o ./lib/Matris.o -c ./src/Matris.cpp
	g++ -I ./include/ -o ./bin/program ./lib/HucreDugum.o ./lib/Matris.o ./src/main.cpp
calistir:
	./bin/program