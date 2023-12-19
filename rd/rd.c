// Input => a+a*a
#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[100];
int i = 0, l;

int E(), T(), F(), EP(), TP();

int main()
{
    printf("Recursive descent parsing for the grammar:\n");
    printf("E -> TEP\n");
    printf("T -> FTP\n");
    printf("F -> (E) | ID\n");

    printf("Enter the string to check: ");
    scanf("%s", input);

    l = strlen(input);
    input[l] = '$'; // Adding '$' at the end to mark the end of the input

    if (E() && i == l)
    {
        printf("String is accepted\n");
    }
    else
    {
        printf("String is not accepted\n");
    }

    return 0;
}

int E()
{
    return T() && EP();
}

int EP()
{
    return (input[i] == '+' && (++i, T() && EP())) || 1; // ε production
}

int T()
{
    return F() && TP();
}

int TP()
{
    return (input[i] == '*' && (++i, F() && TP())) || 1; // ε production
}

int F()
{
    if (input[i] == '(')
    {
        i++;
        if (E() && input[i] == ')')
        {
            i++;
            return 1;
        }
    }
    else if (isalpha(input[i]))
    {
        i++;
        return 1;
    }
    return 0;
}
