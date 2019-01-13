all:
	g++ -std=c++11 -o run main.cpp `pkg-config --cflags --libs opencv`;
	./run;
