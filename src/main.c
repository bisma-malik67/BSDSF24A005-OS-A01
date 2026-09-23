#include <stdio.h>
#include <stdlib.h>
#include "../include/mystrfunctions.h"
#include "../include/myfilefunctions.h"

int main() {
    printf("--- Testing String Functions ---\n");
    
    char myString[] = "Hello";
    int len = mystrlen(myString);
    
    printf("Length of '%s' is: %d\n", myString, len);
    
        char dest1[50];
    mystrcpy(dest1, "Copy this");
    printf("mystrcpy result: %s\n", dest1);
    
    char dest2[50];
    mystrncpy(dest2, "Truncate", 5);
    printf("mystrncpy result: %s\n", dest2);
    
    char dest3[50] = "Hello ";
    mystrcat(dest3, "World");
    printf("mystrcat result: %s\n", dest3);

    printf("\n--- Testing File Functions ---\n");
    
        FILE* fp = fopen("test.txt", "r");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    int lines, words, chars;
    wordCount(fp, &lines, &words, &chars);
    printf("Lines: %d, Words: %d, Chars: %d\n", lines, words, chars);
    
    fclose(fp);
    
        FILE* fp2 = fopen("test.txt", "r");
    char** matches;
    int matchCount = mygrep(fp2, "line", &matches);
    
    printf("Found %d lines containing 'line':\n", matchCount);
    for (int i = 0; i < matchCount; i++) {
        printf("  %s", matches[i]);
    }
    
    fclose(fp2);

    return 0;
}
