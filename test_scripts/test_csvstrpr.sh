#!/bin/bash

cat ../test_data/grid.csv | valgrind ../csvstrpr --include --index 2,3
