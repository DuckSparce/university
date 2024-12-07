#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_SIZE 1000

void infixToPostfix(char[MAX_SIZE], char[MAX_SIZE]);
int isOperator(char);
int precedence(char);

// Stack functions
void push(char[MAX_SIZE], int *, char);
char pop(char[MAX_SIZE], int *);
char peek(char[MAX_SIZE], int);

int computePostfix(char postfix[]);

int main()
{
    char infix[MAX_SIZE];
    char postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    fgets(infix, MAX_SIZE, stdin);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    int res = computePostfix(postfix);

    return 0;
}

void infixToPostfix(char infix[MAX_SIZE], char postfix[MAX_SIZE])
{
    char stack[MAX_SIZE];
    int top = -1;

    int j = 0;
    char ch;

    for (int i = 0; infix[i] != '\0'; i++)
    {
        ch = infix[i];

        if (isalnum(ch))
        {
            postfix[j] = ch;
            j++;
        }
        else if (ch == '(')
        {
            push(stack, &top, ch);
        }
        else if (ch == ')')
        {
            while (peek(stack, top) != '(')
            {
                postfix[j++] = pop(stack, &top);
            }
            pop(stack, &top);
        }
        else if (isOperator(ch))
        {
            while (top != -1 && precedence(peek(stack, top)) >= precedence(ch))
            {
                postfix[j++] = pop(stack, &top);
            }
            push(stack, &top, ch);
        }
    }

    while (top != -1)
    {
        postfix[j++] = pop(stack, &top);
    }

    postfix[j] = '\0';
}

int isOperator(char ch)
{
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char operator)
{
    switch (operator)
    {
    case '+': return 1;
    case '-': return 1;
    case '*': return 2;
    case '/': return 2;
    case '^': return 3;
    default: return 0;
    }
}

void push(char stack[MAX_SIZE], int *top, char item)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack[++(*top)] = item;
}

char pop(char stack[MAX_SIZE], int *top)
{
    if (*top == -1)
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack[(*top)--];
}

char peek(char stack[MAX_SIZE], int top)
{
    if (top == -1)
    {
        return '\0'; // Return null character for an empty stack
    }
    return stack[top];
}

int computePostfix(char postfix[])
{
    int stack[MAX_SIZE];
    int top = -1;

    int i, operand, result;
    char ch;

    printf("Operation\n");

    for (i = 0; postfix[i] != '\0'; i++)
    {
        ch = postfix[i];

        if (isdigit(ch))
        {
            push(stack, &top, ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            int operand2 = pop(stack, &top);
            int operand1 = pop(stack, &top);

            switch (ch) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    if (operand2 == 0) {
                        printf("Error: Division by zero\n");
                        exit(EXIT_FAILURE);
                    }
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Error: Invalid operator\n");
                    exit(EXIT_FAILURE);
            }

            push(stack, &top, result);

            // Print the current step
            printf("%c %d %d\n", ch, operand1, operand2);
        }
        else
        {
            printf("Error: Invalid character in postfix expression\n");
            exit(EXIT_FAILURE);
        }
    }

    // The final result is at the top of the stack
    printf("Result: %d\n", pop(stack, &top));
}