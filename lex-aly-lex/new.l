%{
#include<stdio.h>
%}

%%
if|else|switch|while|for|return|int|void|main|float|do   { printf("it is a keyword=%s\n", yytext); }
[a-zA-Z][a-zA-Z0-9]*   { printf("it is an identifier=%s\n", yytext); }
"{"|"}"|"\["|"\]"|"("|")"   { printf("paranthesis=%s\n", yytext); }
","|";"|\.   { printf("punctuation=%s\n", yytext); }
"\*"|"\-"|"\/"|"\+"|"=" {printf("it is an operator=%s\n",yytext);}
%%

int yywrap() {
    return 1;  
}

int main()
{
    FILE *fp = fopen("text", "r");
    yyin = fp;
    printf("enter the string");
    yylex();
    return 0;
}
