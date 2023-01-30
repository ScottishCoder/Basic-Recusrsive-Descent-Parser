#include <stdio.h>

/*
  parse_rule::=expression;
  expression_rule::= expression + expression
| expression - expression
| expression * expression
| expression / expression
| '(' expression ')'
| int ;
  int_rule::= 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 ;
 */

char lookahead;
void parse_rule();
void expression_rule();
void int_rule();
void match(char t);

int main() {

    printf("Enter Expression: ");
    lookahead = getchar();

    parse_rule();
    if(lookahead == '#')
    {
        printf("Passed Parse");
    }

    return 0;
}

void parse_rule()
{
    printf("\nEntered parse_rule\n");
    expression_rule();
}

void expression_rule()
{
    printf("Entered expression_rule\n");

    int_rule();

    if(lookahead == '+')
    {
        printf("we matched operator [+]\n");
        match('+');
        expression_rule();
    }
    if(lookahead == '-'){
        printf("we matched operator [-]\n");
        match('-');
        expression_rule();
    }

    if(lookahead == '*'){
        printf("we matched operator [*]\n");
        match('*');
        expression_rule();
    }

    if(lookahead == '/'){
        printf("we matched operator [/]\n");
        match('/');
        expression_rule();
    }
    if(lookahead == '(')
    {
        printf("we matched open parens [(]\n");
        match('(');
        expression_rule();
        match(')');
        printf("we matched closed parens [)]\n");
    }


    printf("Exited expression_rule\n");

}
void int_rule()
{
    printf("Entered int_rule\n");

    if(lookahead == '0')
    {
        match('0');
    }
    else if(lookahead == '1'){
        printf("we matched integer 1\n");
        match('1');
    }

    else if(lookahead == '2'){
        printf("we matched integer 2\n");
        match('2');

    }

    else if(lookahead == '3'){
        printf("we matched integer 3\n");
        match('3');
    }
    else if(lookahead == '4')
    {
        printf("we matched integer 4\n");
        match('4');

    }

    else if(lookahead == '5')
    {
        printf("we matched integer 5\n");
        match('5');

    }

    else if(lookahead == '6')
    {
        printf("we matched integer 6\n");
        match('6');

    }

    else if(lookahead == '7')
    {
        printf("we matched integer 7\n");
        match('7');

    }

    else if(lookahead == '8')
    {
        printf("we matched integer 8\n");
        match('8');
    }

    else if(lookahead == '9')
    {
        printf("we matched integer 9\n");
        match('9');
    }

    printf("Exited int_rule\n");

}
void match(char t)
{
    if(lookahead == t)
    {
        lookahead = (char)getchar();
    }
    else
    {
        printf("Error Parsing");
    }
}