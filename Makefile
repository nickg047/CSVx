default: build

csvfltr: csvfltr.cpp common.o
	g++ -o csvfltr common.o csvfltr.cpp

csvmtrx: csvmtrx.cpp common.o
	g++ -o csvmtrx common.o csvmtrx.cpp

csvstr: csvstr.cpp
	g++ -o csvstr csvstr.cpp

csvstrpr: csvstrpr.cpp
	g++ -o csvstrpr csvstrpr.cpp

common.o: common.cpp
	g++ -c common.cpp

build: csvfltr csvmtrx csvstr csvstrpr

clean:
	rm -f ./csvfltr
	rm -f ./csvmtrx
	rm -f ./csvstr
	rm -f ./csvstrpr
	rm -f ./common.o

install:
	cp ./csvfltr /usr/local/bin/csvfltr
	cp ./csvmtrx /usr/local/bin/csvmtrx
	cp ./csvstr /usr/local/bin/csvstr
	cp ./csvstrpr /usr/local/bin/csvstrpr

uninstall:
	rm -f /usr/local/bin/csvfltr
	rm -f /usr/local/bin/csvmtrx
	rm -f /usr/local/bin/csvstr
	rm -f /usr/local/bin/csvstrpr
