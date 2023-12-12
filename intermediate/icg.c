#include <stdio.h>
#include <string.h>

int i = 1, j = 0, tmpch = 90;
char str[100], left[15], right[15];

struct exp {
    int pos;
    char op;
} k[15];

void findopr();
void explore();
void process_side(char[], int, int, int);

void main() {
    printf("\t\tINTERMEDIATE CODE GENERATION\n\n");
    printf("Enter the Expression :");
    scanf("%s", str);
    printf("The intermediate code:\t\tExpression\n");
    findopr();
    explore();
}

void findopr() {
    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == ':') {
            k[j].pos = i;
            k[j++].op = ':';
        } else if (str[i] == '/') {
            k[j].pos = i;
            k[j++].op = '/';
        } else if (str[i] == '*') {
            k[j].pos = i;
            k[j++].op = '*';
        } else if (str[i] == '+') {
            k[j].pos = i;
            k[j++].op = '+';
        } else if (str[i] == '-') {
            k[j].pos = i;
            k[j++].op = '-';
        }
    }
}

void explore() {
    i = 0;
    while (k[i].op != '\0') {
        process_side(left, k[i].pos, -1, -1);
        process_side(right, k[i].pos, 1, 1);
        str[k[i].pos] = tmpch--;
        printf("\t%c := %s%c%s\t\t", str[k[i].pos], left, k[i].op, right);
        for (j = 0; j < strlen(str); j++) {
            if (str[j] != '$') {
                printf("%c", str[j]);
            }
        }
        printf("\n");
        i++;
    }
}

void process_side(char side[], int x, int direction, int flag_value) {
    int w = 0, flag = 0;
    x += direction;
    while (x >= 0 && str[x] != '+' && str[x] != '*' && str[x] != '=' && str[x] != '\0' && str[x] != '-' && str[x] != '/' && str[x] != ':') {
        if (str[x] != '$' && flag == 0) {
            side[w++] = str[x];
            side[w] = '\0';
            str[x] = '$';
            flag = flag_value;
        }
        x += direction;
    }
}
