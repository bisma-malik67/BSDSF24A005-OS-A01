#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/myfilefunctions.h"
int wordCount(FILE* file, int* lines, int* words, int* chars) {
int c;
int inWord = 0;
*lines = 0;
*words = 0;
*chars = 0;
while ((c = fgetc(file)) != EOF) {
(*chars)++;
if (c == '\n') {
(*lines)++;
}
if (c == ' ' || c == '\n' || c == '\t') {
inWord = 0;
} else {
if (inWord == 0) {
(*words)++;
inWord = 1;
}}
}
return 0;
}
int mygrep(FILE* fp, const char* search_str, char*** matches) {
    char buffer[1000];
    int count = 0;

    // Maximum 100 matching lines
    *matches = malloc(100 * sizeof(char*));

    while (fgets(buffer, 1000, fp) != NULL) {

        // Check if search string exists in current line
        if (strstr(buffer, search_str) != NULL) {

            // Allocate memory for the matching line
            (*matches)[count] = malloc(strlen(buffer) + 1);

            // Copy the line into allocated memory
            strcpy((*matches)[count], buffer);

            // Increase match count
            count++;
        }
    }

    return count;
}
