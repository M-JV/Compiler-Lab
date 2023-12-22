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

void main() {
    char ch, buffer[15];
    FILE *fp,*f2;
    int j = 0,line = 1,tk=0;

    fp = fopen("input.txt", "r");
    f2 = fopen("write.txt","w");
    if (fp == NULL || f2 == NULL) {
        printf("Error while opening the file\n");
        exit(0);
    }

    fprintf(f2,"Line No\t Token No\t Token\t\t Lexime\t\n");
    fprintf(f2,"--------------------------------------------------\n");
    printf("Line No\t Token No\t Token\t Lexime\t\n");
    printf("--------------------------------------------------\n");
    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch)) {
            buffer[j++] = ch;
        } else if (isOperator(ch) || ch == ';') {
            if (j != 0) {
                buffer[j] = '\0';
                printf("%d\t %d\t %s is identifier\n",line,tk,buffer);
                fprintf(f2,"%d\t\t\t %d\t\t%s\t\t  identifier\n",line,tk,buffer);
                tk++;
                j = 0;
            }
            printf(ch==';' ? "%d\t %d\t %c is Special symbol\n" : "%d\t\t %d\t%c is identifier\n",line,tk,ch);
            fprintf(f2,ch==';' ? "%d\t\t\t %d\t\t %c\t\t Special symbol\n" : "%d\t\t\t %d\t\t%c\t\t identifier\n",line,tk,ch);
            tk++;
        } else if ((ch == ' ' || ch == '\n') && (j != 0)) {
            if(ch=='\n')
                line++;
            buffer[j] = '\0';
            j = 0;
            printf(isKeyword(buffer) ? "%d\t %d\t%s is keyword\n" : "%d\t %d\t%s is identifier\n",tk,line,buffer);
            fprintf(f2,isKeyword(buffer) ? "%d\t\t\t %d\t\t%s\t\t keyword\n" : "%d\t\t\t %d\t\t%s\t\t identifier\n",tk,line,buffer);
            tk++;
        }
        else if(ch == '\n'){
            line++;
        }
    }
    printf("--------------------------------------------------\n");
    fprintf(f2,"--------------------------------------------------\n");

    fclose(fp);
    fclose(f2);
}
