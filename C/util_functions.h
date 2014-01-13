/*
 * Header file for utility functions
 * Author: Arvind S Raj
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Reads until newline('\n'), stores in buf and returns count of chars read.
int read_line(FILE *fh, char **buf);

// Reads until last_char, stores in buf and returns count of chars read.
int read_until(FILE *fh, char **buf, char last_char);
