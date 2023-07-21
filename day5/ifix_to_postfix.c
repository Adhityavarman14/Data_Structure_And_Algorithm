#include <stdio.h>
#include <string.h>
#include <conio.h>
#define MAX 20

int top = -1;
char stack[MAX];

char pop();
void push(char item);
int prcd(char symbol);
int isoperator(char symbol);
void converter(char infix[], char postfix[]);

void main()
{
    char infix[20], postfix[20]; // arrays are passed as reference
    //clrscr();
    
    printf("$$$ INFIX TO POSTFIX CONVERTER $$$\n\nEnter the valid infix expression: ");
    scanf("%s", infix);
    converter(infix, postfix);
    printf("Postfix expression: ");
    printf("%s", postfix);
}

void converter(char infix[], char postfix[])
{
    int i, symbol, j = 0;
    stack[++top] = '#';
    
    for(i = 0; i < strlen(infix); i++)
    {
        symbol = infix[i];
        
        if(isoperator(symbol) == 0) // This part works when the character is operand
        {
            postfix[j] = symbol;
            j++;
        }
        else
        {
            if(symbol == '(')
            {
                push(symbol);
            }
            else if(symbol == ')')
            {
                while(stack[top] != '(')
                {
                    postfix[j] = pop();
                    j++;
                }
                pop();
            }
            else
            {
                if(prcd(symbol) > prcd(stack[top]))
                {
                    push(symbol);
                }
                else
                {
                    while(prcd(symbol) <= prcd(stack[top]))
                    {
                        postfix[j] = pop();
                        j++;
                    }
                    push(symbol);
                }
            }
        }
    }
    
    while(stack[top] != '#')
    {
        postfix[j] = pop();
        j++;
    }
    postfix[j] = '\0';
}

int isoperator(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
        case '*':
        case '/':
        case '^':
        // case '$':
        case '(':
        case ')':
            return 1;
        default:
            return 0;
    }
}

int prcd(char symbol)
{
    switch(symbol)
    {
        case '+':
        case '-':
            return 2;
        case '*':
        case '/':
            return 4;
        case '^':
        // case '$':
            return 6;
        case '(':
        case ')':
        case '#':
            return 1;
        default:
            return 0;
    }
}


void push(char item)
{
    top++;
    stack[top] = item;
}

char pop()
{
    char a;
    a = stack[top];
    top--;
    
    return a;
}
