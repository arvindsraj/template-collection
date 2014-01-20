/*
 * Header file for utility functions
 * Author: Arvind S Raj
 *
 */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Free dynamically allocated memory
void free_string_array(char **, int);

// Reads until newline('\n') and stores in buf. Uses read_until internally.
char read_line(FILE *fh, char **buf);

// Reads all lines till EOF. Returns number of lines read.
int read_lines(FILE *fh, char ***buf);

// Reads until last_char, stores in buf and returns last character read; useful to check if EOF.
char read_until(FILE *fh, char **buf, char last_char);

// Split a string based on a character. Return pointer to all components; store number of components in last argument.
/* TODO: Doesn't work as advertised always */
char** split(char *, char, int *);
