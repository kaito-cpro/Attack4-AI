
out: obj/main.o obj/game.o obj/Player.o obj/Human.o obj/AI.o
	g++ -o exe/out obj/main.o obj/game.o obj/Player.o obj/Human.o obj/AI.o

obj/main.o: src/main.cpp
	g++ -c src/main.cpp -I hdr -o obj/main.o

obj/game.o: src/game.cpp
	g++ -c src/game.cpp -I hdr -o obj/game.o

obj/Player.o: src/Player.cpp
	g++ -c src/Player.cpp -I hdr -o obj/Player.o

obj/Human.o: src/Human.cpp
	g++ -c src/Human.cpp -I hdr -o obj/Human.o

obj/AI.o: src/AI.cpp
	g++ -c src/AI.cpp -I hdr -o obj/AI.o
