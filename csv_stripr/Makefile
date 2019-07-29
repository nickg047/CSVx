build:
	g++ -o csvstrpr csvstrpr.cpp

default: build

clean:
	rm -f ./csvstrpr

fresh:
	make clean
	make

install:
	cp ./csvstrpr /usr/local/bin/csvstrpr

uninstall:
	rm -f /usr/local/bin/csvstrpr

test:
	cat input1 | ./csvstrpr --include --index 2,5
	#todo - unified test data

memtest:
	cat input1 | valgrind ./csvstrpr --include --index 2,5
	#todo
