## CSV FILTER ##

build_csvfltr:
	make -C ./csv_filter build

clean_csvfltr: 
	make -C ./csv_filter clean

install_csvfltr:
	make -C ./csv_filter install

uninstall_csvfltr:
	make -C ./csv_filter uninstall

test_csvfltr:
	make -C ./csv_filter test

memtest_csvfltr:
	make -C ./csv_filter memtest

## CSV METRICS ##

build_csvmtrx:
	make -C ./csv_metrics build

clean_csvmtrx:
	make -C ./csv_metrics clean

install_csvmtrx:
	make -C ./csv_metrics install

uninstall_csvmtrx:
	make -C ./csv_metrics uninstall

test_csvmtrx:
	make -C ./csv_metrics test

memtest_csvmtrx:
	make -C ./csv_metrics memtest

## CSV STRING-ER ##

build_csvstr:
	make -C ./csv_stringer build

clean_csvstr:
	make -C ./csv_stringer clean

install_csvstr:
	make -C ./csv_stringer install

uninstall_csvstr:
	make -C ./csv_stringer uninstall

test_csvstr:
	make -C ./csv_stringer test

memtest_csvstr:
	make -C ./csv_stringer memtest


## CSV STRIPPER ##

build_csvstrpr:
	make -C ./csv_stripr build

clean_csvstrpr:
	make -C ./csv_stripr clean

install_csvstrpr:
	make -C ./csv_stripr install

uninstall_csvstrpr:
	make -C ./csv_stripr uninstall

test_csvstrpr:
	make -C ./csv_stripr test

memtest_csvstrpr:
	make -C ./csv_stripr memtest

## ALL TARGETS ##

build_all: build_csvfltr build_csvmtrx build_csvstr build_csvstrpr
build: build_all
default: build

clean_all: clean_csvfltr clean_csvmtrx clean_csvstr clean_csvstrpr
clean: clean_all

install_all: install_csvfltr install_csvmtrx install_csvstr install_csvstrpr
install: install_all

uninstall_all: uninstall_csvfltr uninstall_csvmtrx uninstall_csvstr uninstall_csvstrpr
uninstall: uninstall_all

test_all:
	# TODO - dont call test on all targets.. run different chaining tests

test: test_all

memtest_all: memtest_csvfltr memtest_csvmtrx memtest_csvstr memtest_csvstrpr
memtest: memtest_all
