#include <stdio.h>
#define max 30
#include <string.h>
#include <stdlib.h>
int top = -1;
char stack[max];
char postfix[max];
void push(char c)
{
    if (top == max - 1)
    {
        printf("stack-overflow.\n");
        exit(1);
    }
    else
    {
        top++;
        stack[top] = c;
    }
}
int pop()
{
    if (top == -1)
    {
        printf("stack-underflow.\n");
        return -1;
    }
    else
    {
        int temp = top;
        top--;
        return temp;
    }
}
int priority(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return -1;
    }
}
void infix_to_postfix(char infix[])
{
    int k = 0;
    for (int i = 0; i < strlen(infix); i++)
    {
        // printf("stack %s\n", stack);
        if (infix[i] != ' ')
        {
            if (infix[i] >= '0' && infix[i] <= '9')
            {
                postfix[k] = infix[i];
                k++;
            }
            else if (infix[i] == '(')
            {
                push(infix[i]);
            }
            else if (infix[i] == ')')
            {
                while (top > -1 && stack[top] != '(')
                {
                    int temp = pop();
                    postfix[k++] = stack[temp];
                }
                if (stack[top] != '(')
                {
                    printf("invalid expression");
                }
                else
                {
                    top--;
                }
            }
            else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/' || infix[i] == '^')
            {
                while (top > -1 && priority(stack[top]) >= priority(infix[i]))
                {
                    int temp = pop();
                    postfix[k++] = stack[temp];
                }
                push(infix[i]);
            }
            postfix[k] = '\0'; // a+b-c*d/e(f+s-g^h)
        }
    }
    while (top > -1)
    {
        int temp = pop();
        postfix[k++] = stack[temp];
    }
}
int eval()
{
    for (int i = 0; i < strlen(postfix); i++)
    {
        if (postfix[i] >= '0' && postfix[i] <= '9')
        {
            push(postfix[i]);
        }
        else
        {

            printf("\n%s", stack);
            while (top > -1)
            {
                if (postfix[i] == '+' || postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/' || postfix[i] == '^')
                {
                    int a = pop();
                    int b = pop();
                    int e = stack[a] - '0';
                    int f = stack[b] - '0';
                    printf("\ne=%d  f=%d  a=%c  b=%d    c=%d 0=%d\n", e, f, stack[a], stack[b],'0');
                    char temp;
                    switch (a)
                    {
                    case '+':
                        push(e + f);
                        break;
                    case '-':
                        push(e - f);

                        break;
                    case '*':
                        push(e * f);

                        break;
                    case '/':
                        push(e / f);
                        break;
                    case '^':
                        push(e ^ f);
                        break;
                    }
                }
            }
        }
    }

    int temp = pop();
    int value = stack[temp];
    printf("value is %d", value);
}
int main()
{
    char infix[max];
    printf("Enter the infix Expression: ");
    scanf("%[^\n]%*c", infix);
    infix_to_postfix(infix);
    printf("postfix expression is: ");
    printf("%s", postfix);
    eval();
}