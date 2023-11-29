#include <stdio.h>
#include <string.h>

char input[100];
int i = 0, l;

int E();
int EP();
int T();
int TP();
int F();

int main() {
    printf("Recursive descent parsing for the grammar:\n");
    printf("E -> TEP\n");
    printf("EP -> +TEP | ε\n");
    printf("T -> FTP\n");
    printf("TP -> *FTP | ε\n");
    printf("F -> (E) | ID\n");
    
    printf("Enter the string to check: ");
    scanf("%s", input);
    
    l = strlen(input);
    input[l] = '$'; // Adding '$' at the end to mark the end of the input
    
    if (E() && i == l) {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }

    return 0;
}

int E() {
    if (T()) {
        if (EP()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int EP() {
    if (input[i] == '+') {
        i++;
        if (T()) {
            if (EP()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 1; // ε production
    }
}

int T() {
    if (F()) {
        if (TP()) {
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

int TP() {
    if (input[i] == '*') {
        i++;
        if (F()) {
            if (TP()) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 1; // ε production
    }
}

int F() {
    if (input[i] == '(') {
        i++;
        if (E()) {
            if (input[i] == ')') {
                i++;
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if ((input[i] >= 'a' && input[i] <= 'z') || (input[i] >= 'A' && input[i] <= 'Z')) {
        i++;
        return 1;
    } else {
        return 0;
    }
}
