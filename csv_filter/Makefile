build:
	g++ -o csvfltr csvfltr.cpp

default: build

install:
	cp ./csvfltr /usr/local/bin/csvfltr

uninstall:
	rm -f /usr/local/bin/csvfltr

clean:
	rm -f csvfltr

test:
	cat test.csv | ./csvfltr -h KICKOUTMSG -v AutoPackFailed

memtest:
	cat test.csv | valgrind ./csvfltr -h KICKOUTMSG -v AutoPackFailed
