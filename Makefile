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

common.o: common.cpp
	$(CC) $(CFLAGS) -c common.cpp

build: csvfltr csvmtrx csvstr csvstrpr rowstrpr

clean:
	rm -f ./csvfltr
	rm -f ./csvmtrx
	rm -f ./csvstr
	rm -f ./csvstrpr
	rm -f ./rowstrpr
	rm -f ./common.o

install:
	cp ./csvfltr /usr/local/bin/csvfltr
	cp ./csvmtrx /usr/local/bin/csvmtrx
	cp ./csvstr /usr/local/bin/csvstr
	cp ./csvstrpr /usr/local/bin/csvstrpr
	cp ./rowstrpr /usr/local/bin/rowstrpr

uninstall:
	rm -f /usr/local/bin/csvfltr
	rm -f /usr/local/bin/csvmtrx
	rm -f /usr/local/bin/csvstr
	rm -f /usr/local/bin/csvstrpr
	rm -f /usr/local/bin/rowstrpr
