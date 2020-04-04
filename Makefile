CC = g++
CFLAGS = -std=c++11

default: build

csvfltr: csvfltr.cpp common.o
	$(CC) $(CFLAGS) -o csvfltr common.o csvfltr.cpp

csvmtrx: csvmtrx.cpp common.o
	$(CC) $(CFLAGS) -o csvmtrx common.o csvmtrx.cpp

csvstr: csvstr.cpp common.o
	$(CC) $(CFLAGS) -o csvstr common.o csvstr.cpp

csvstrpr: csvstrpr.cpp common.o
	$(CC) $(CFLAGS) -o csvstrpr common.o csvstrpr.cpp

rowstrpr: rowstrpr.cpp common.o
	$(CC) $(CFLAGS) -o rowstrpr common.o rowstrpr.cpp

csvprinter: csvprinter.cpp common.o matrix.o
	$(CC) $(CFLAGS) -o csvprinter common.o matrix.o csvprinter.cpp

csvjson: csvjson.cpp common.o
	$(CC) $(CFLAGS) -o csvjson common.o

matrix.o: matrix.cpp
	$(CC) $(CFLAGS) -c matrix.cpp

common.o: common.cpp
	$(CC) $(CFLAGS) -c common.cpp

build: csvfltr csvmtrx csvstr csvstrpr csvprinter rowstrpr

clean:
	rm -f ./csvfltr
	rm -f ./csvmtrx
	rm -f ./csvstr
	rm -f ./csvstrpr
	rm -f ./rowstrpr
	rm -f ./common.o
	rm -f ./matrix.o
	rm -f ./csvprinter
	rm -f ./csvjson

install:
	cp ./csvfltr /usr/local/bin/csvfltr
	cp ./csvmtrx /usr/local/bin/csvmtrx
	cp ./csvstr /usr/local/bin/csvstr
	cp ./csvstrpr /usr/local/bin/csvstrpr
	cp ./csvprinter /usr/local/bin/csvprinter
	cp ./rowstrpr /usr/local/bin/rowstrpr
	cp ./csvjson /usr/local/bin/csvjson

uninstall:
	rm -f /usr/local/bin/csvfltr
	rm -f /usr/local/bin/csvmtrx
	rm -f /usr/local/bin/csvstr
	rm -f /usr/local/bin/csvstrpr
	rm -f /usr/local/bin/csvprinter
	rm -f /usr/local/bin/rowstrpr
	rm -f /usr/local/bin/csvjson
