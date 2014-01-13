/*
 * Header file for utility functions
 * Author: Arvind S Raj
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Reads until newline('\n') and stores in buf. Uses read_until internally.
char read_line(FILE *fh, char **buf);

// Reads all lines till EOF. Returns number of lines read.
int read_lines(FILE *fh, char ***buf);

// Reads until last_char, stores in buf and returns last character read; useful to check if EOF.
char read_until(FILE *fh, char **buf, char last_char);
