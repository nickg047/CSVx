default: build

csvfltr: csvfltr.cpp common.o
	g++ -o csvfltr common.o csvfltr.cpp

csvmtrx: csvmtrx.cpp common.o
	g++ -o csvmtrx common.o csvmtrx.cpp

csvstr: csvstr.cpp common.o
	g++ -o csvstr common.o csvstr.cpp

csvstrpr: csvstrpr.cpp common.o
	g++ -o csvstrpr common.o csvstrpr.cpp

csvprinter: csvprinter.cpp common.o matrix.o
	g++ -o csvprinter common.o matrix.o csvprinter.cpp

matrix.o: matrix.cpp
	g++ -c matrix.cpp

common.o: common.cpp
	g++ -c common.cpp

build: csvfltr csvmtrx csvstr csvstrpr csvprinter

clean:
	rm -f ./csvfltr
	rm -f ./csvmtrx
	rm -f ./csvstr
	rm -f ./csvstrpr
	rm -f ./common.o
	rm -f ./matrix.o
	rm -f ./csvprinter

install:
	cp ./csvfltr /usr/local/bin/csvfltr
	cp ./csvmtrx /usr/local/bin/csvmtrx
	cp ./csvstr /usr/local/bin/csvstr
	cp ./csvstrpr /usr/local/bin/csvstrpr
	cp ./csvprinter /usr/local/bin/csvprinter

uninstall:
	rm -f /usr/local/bin/csvfltr
	rm -f /usr/local/bin/csvmtrx
	rm -f /usr/local/bin/csvstr
	rm -f /usr/local/bin/csvstrpr
	rm -f /usr/local/bin/csvprinter

