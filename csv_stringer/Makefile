build:
	g++ -o csvstr csvstr.cpp

default: build

install:
	cp ./csvstr /usr/local/bin/csvstr

uninstall:
	rm -f /usr/local/bin/csvstr

clean:
	rm -f csvstr

test:
	cat test | ./csvstr
	#todo

memtest:
	cat test | valgrind ./csvstr
	#todo
