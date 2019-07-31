default: build

csvfltr: csvfltr.cpp
	g++ -o csvfltr csvfltr.cpp

csvmtrx: csvmtrx.cpp
	g++ -o csvmtrx csvmtrx.cpp

csvstr: csvstr.cpp
	g++ -o csvstr csvstr.cpp

csvstrpr: csvstrpr.cpp
	g++ -o csvstrpr csvstrpr.cpp

build: csvfltr csvmtrx csvstr csvstrpr

clean:
	rm -f ./csvfltr
	rm -f ./csvmtrx
	rm -f ./csvstr
	rm -f ./csvstrpr

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
