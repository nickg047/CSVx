# CSVx
CSV Transformation Tools

## Description
Tools and utilities for on-the-fly csv transformation, formatting and metric calculations.

## Compilation
To compile and install all the tools simply type:  
`make`  
`sudo make install`

## Usage

### CSV FILTER
`csvfltr -h [HEADERS] -v [VALUES]`	
	
Headers and Values must be entered in respective order and are comma separated	
	
Values can either be string literals or commands such as:	
        '/<0'             - Negative Value	
        '/>0'             - Positive Value	
        '/0'              - Empty String	
        '/c[STRING]'      - Contained String	
		
csvfltr will then listen for input from stdin	

### CSV METRICS
Calculates occurance metrics in a CSV matrix	

`csvmtrx`	

csvmtrx will then listen for input from stdin	

### CSV STRING
Stringifies CSV values for proper display in applications like MS Excel	

`csvstr`	

csvstr will then listen for input from stdin	

### CSV STRIPPER
Removes columns from csv output	

Usage:	
`csvstrpr [FLAGS] [HEADERS]`	

Flags:	
--index   : Specified headers are column numbers instead of header strings	
--include : Include only the specified headers in output	

Headers must be provided as a string of comma separated values	

csvstrpr will then listen for input from stdin	