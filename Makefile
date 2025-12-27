all: start

start: *.cpp
		g++ -o start *.cpp -lncurses

clean:
		rm -f start
