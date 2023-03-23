CFLAGS = -std=c++20 -O2
LDFLAGS = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi

Xplor: main.cpp
	g++ $(CFLAGS) -o Xplor main.cpp $(LDFLAGS)

test: Xplor
	./Xplor

clean:
	rm -f Xplor