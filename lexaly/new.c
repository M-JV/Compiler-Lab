#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[]) {
    char keywords[32][10] = {"char", "do", "else", "float", "for", "if", "int", "while", "main", "void"};
    for (int i = 0; i < 10; ++i) {
        if (strcmp(keywords[i], buffer) == 0) {
            return 1;
        }
    }
    return 0;
}

int isOperator(char ch) {
    char operators[] = "+-*/%";
    for (int i = 0; i < 5; ++i) {
        if (ch == operators[i]) {
            return 1;
        }
    }
    return 0;
}

int main() {
    char ch, buffer[15];
    FILE *fp;
    int j = 0;

    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if (isOperator(ch) || ch == ';') {
            if (j != 0) {
                buffer[j] = '\0';
                printf("%s is identifier\n", buffer);
                j = 0;
            }
            printf(ch == ';' ? "; is special symbol\n" : "%c is operator\n", ch);
        } else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;
            printf(isKeyword(buffer) ? "%s is keyword\n" : "%s is identifier\n", buffer);
        }
    }

    fclose(fp);
    return 0;
}
