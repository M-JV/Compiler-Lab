#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_KEYWORDS 30
#define MAX_IDENTIFIER_LENGTH 100

int main() {
    FILE *input, *output;
    int line = 1, token = 0;
    char ch, str[MAX_IDENTIFIER_LENGTH];

    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");

    if (input == NULL || output == NULL) {
        printf("Error opening files.\n");
        return 1;
    }

    char keywords[MAX_KEYWORDS][30] = {"int", "main", "if", "else", "do", "while"};

    fprintf(output, "Line no.\t Token no.\t Token\t Lexeme\n\n");

    while (fscanf(input, "%c", &ch) != EOF) {
        if (isspace(ch)) {
            continue; // Skip whitespaces
        } else if (isalpha(ch) || ch == '_') {
            int i = 0;
            str[i++] = ch;

            while (isalnum(ch) || ch == '_') {
                fscanf(input, "%c", &ch);
                str[i++] = ch;
            }

            str[i] = '\0';

            int isKeyword = 0;
            for (int j = 0; j < MAX_KEYWORDS; j++) {
                if (strcmp(str, keywords[j]) == 0) {
                    isKeyword = 1;
                    break;
                }
            }

            fprintf(output, "%7d\t\t%7d\t\t%s\t%7s\n", line, token, isKeyword ? "Keyword" : "Identifier", str);
            token++;
        } else if (isdigit(ch)) {
            fprintf(output, "%7d\t\t%7d\t\tDigit\t\t%7c\n", line, token, ch);
            token++;
        } else if (strchr("+-*/%{}()[];:,.<>=!", ch) != NULL) {
            fprintf(output, "%7d\t\t%7d\t\tSpecial Symbol\t%7c\n", line, token, ch);
            token++;
        } else if (ch == '\n') {
            line++;
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}
