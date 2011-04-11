snake:
	g++ -c piece.cpp
	g++ -c snake.cpp
	g++ -c point.cpp
	g++ -o snake piece.o snake.o point.o main.cpp -lSDL -lSDL_image
