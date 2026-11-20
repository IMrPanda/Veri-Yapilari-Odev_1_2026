all: derle calistir

derle:
	g++ -I ./include/ -o ./lib/HucreDugum.o -c ./src/HucreDugum.cpp
	g++ -I ./include/ -o ./lib/Matris.o -c ./src/Matris.cpp
	g++ -I ./include/ -o ./lib/ListeDugum.o -c ./src/ListeDugum.cpp
	g++ -I ./include/ -o ./lib/AnaListe.o -c ./src/AnaListe.cpp
	g++ -I ./include/ -o ./lib/DosyaYoneticisi.o -c ./src/DosyaYoneticisi.cpp
	g++ -I ./include/ -o ./lib/Uygulama.o -c ./src/Uygulama.cpp
	g++ -I ./include/ -o ./bin/program ./lib/HucreDugum.o ./lib/Matris.o ./lib/ListeDugum.o ./lib/AnaListe.o ./lib/DosyaYoneticisi.o ./lib/Uygulama.o ./src/main.cpp

calistir:
	./bin/program