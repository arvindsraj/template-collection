/*
 * C source file for utility functions
 * Author: Arvind S Raj
 *
 */

#include "util_functions.h"

int read_line(FILE *fh, char **buf) {
    return read_until(fh, buf, '\n');
}

int read_until(FILE *fh, char **buf, char last_char) {
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
    strncpy(*buf, temp, strlen(temp));
    free(temp);
    return count_of_chars_read;
}
