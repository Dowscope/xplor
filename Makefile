CFLAGS = -std=c++20 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

FILES = ./src/*.cpp

Xplor: src/main.cpp
	g++ $(CFLAGS) -o Xplor $(FILES) $(LDFLAGS)

test: Xplor
	./Xplor

clean:
	rm -f Xplor

debug:
	g++  -g $(CFLAGS) -o Xplor $(FILES) $(LDFLAGS)