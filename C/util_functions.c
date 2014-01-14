/*
 * C source file for utility functions
 * Author: Arvind S Raj
 *
 */

#include "util_functions.h"

char read_line(FILE *fh, char **buf) {
    return read_until(fh, buf, '\n');
}

int read_lines(FILE *fh, char ***buf) {
    char chr, **temp=NULL;
    int i = 0, count_read = 0;
    
    while(1) {
        temp = (char **)realloc(temp, sizeof(char *)*(count_read + 10));
        for(i = 0; i < 10; i++) {
            chr = read_line(fh, &temp[i + count_read]);
            if(chr == EOF) {
                goto done;
            }
        }
        count_read += i;
    }

done:
    count_read += i;
    *buf = (char **)malloc(sizeof(char *)*count_read);
    *buf = temp;
    return count_read;
}

char read_until(FILE *fh, char **buf, char last_char) {
    char curr_char, *temp;
    int count_of_chars_read = 0, counter = 0;
    temp = malloc(10);
    while(1) {
        for(counter = 0; counter < 10; counter++) {
            curr_char = fgetc(fh);
            if((curr_char == last_char) || (curr_char == EOF)) {
                temp[count_of_chars_read + counter] = '\0';
                goto done;
            }
            else {
                temp[count_of_chars_read + counter] = curr_char;
            }
        }
        count_of_chars_read += counter;
        temp = realloc(temp, (count_of_chars_read + 10));
    }
done:
    count_of_chars_read += counter;
    *buf = (char *)malloc(strlen(temp) + 1);
    strncpy(*buf, temp, (strlen(temp) + 1));
    free(temp);
    return curr_char;
}

char** split(char *str, char split_char, int *comp) {
    char *temp_str=NULL;
    char **temp = NULL;
    int components = 0, counter = 0;
    int length;
    length = strlen(str);
    temp_str = malloc(length);
    strncpy(temp_str, str, length);
    for(counter = 0; counter < length; counter++) {
        if(temp_str[counter] == split_char) {
            components++;
        }
    }
    components++;
    temp = (char **)malloc(components * sizeof(char *));
    temp[0] = strtok(temp_str, " ");
    for(counter = 1; counter < components; counter++) {
        temp[counter] = strtok(NULL, " ");
    }
    *comp = components;
    return temp;
}
