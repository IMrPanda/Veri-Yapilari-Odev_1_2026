all: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/BagilListe.o -c ./src/BagilListe.cpp
	g++ -I ./include/ -o ./bin/program ./lib/Dugum.o ./lib/BagilListe.o ./src/main.cpp

calistir:
	./bin/program