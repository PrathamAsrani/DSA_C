#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack
{
    int size, top;
    int *data;
};


/* Infix to postfix */
int isFull(struct Stack *s);
int isEmpty(struct Stack *s);
char stacktop(struct Stack *s);
void push(struct Stack *s, char x);
char pop(struct Stack *s);
int isOperator(char ch);
int precedence(char ch);
char *infixToPostfix(char *infix);
/* Infix to postfix */

/* Evaluation to postfix */
int calculation(char c, int num1, int num2);
int int_converter(char c);
void push1(struct Stack *s, int c);
int pop1(struct Stack *s);
int evaluation_of_postfix(char *postfix);
/* Evaluation to postfix */


int main(){
    char *infix = "a+d-e/s";
    printf("The input infix expression : %s\n", infix);
    char *postfix;
    postfix = infixToPostfix(infix);
    printf("Postfix Expression is %s\n", postfix);
    char *postfix_exp = "6+8-9/1";
    int re = evaluation_of_postfix(&postfix_exp);
    printf("The ans : %d\n",re);
}

int isFull(struct Stack *s)
{
    if (s->top == s->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char stacktop(struct Stack *s)
{
    return s->data[s->top];
}

void push(struct Stack *s, char x)
{
    if (isFull(s))
    {
        printf("Stack is full\n");
    }
    else
    {
        s->top++;
        s->data[s->top] = x;
    }
}

char pop(struct Stack *s)
{
    if (isEmpty(s))
    {
        printf("Stack id empty\n");
    }
    else
    {
        char c = s->data[s->top];
        s->top--;
        return c;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        return 1;
    }
    return 0;
}

int precedence(char ch)
{
    if (ch == '/' || ch == '*')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    return 0;
}

char *infixToPostfix(char *infix)
{
    struct Stack *p = (struct Stack *)malloc(sizeof(struct Stack));
    p->size = strlen(infix);
    p->top = -1;
    p->data = (int *)malloc(p->size * sizeof(int));
    char *postfix = (char *)malloc((p->size+1)*sizeof(char));
    // if(!isOperator(infix))
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (!isOperator(infix[i]))
        {
            postfix[j] = infix[i];
            i++;
            j++;
        }else{
            if(precedence(infix[i])>precedence(stacktop(p))){
                push(p, infix[i]);
                i++;
            }else{
                postfix[j] = pop(p);
                j++;
            }
        }
    }
    while (!isEmpty(p))
    {
        postfix[j] = pop(p);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int calculation(char c, int num1, int num2){
    int result;
    switch (c)
    {
    case '+':
        result = num1+num2;
        break;
    case '-':
        result = num1-num2;
        break;
    case '*':
        result = num1*num2;
        break;
    case '/':
        result = num1/num2;
        break;
    case '%':
        result = num1%num2;
        break;
    case '^':
        result = num1^num2;
        break;
    
    default:
        break;
    }
    return result;
}

int int_converter(char c){
    int a = (int)c - 48;
    return a;
}

void push1(struct Stack *s, int c){
    if(isFull(s)){
        printf("Stack is full\n");
    }else{
        s->top++;
        s->data[s->top] = c;
    }
}

int pop1(struct Stack *s){
    if(isEmpty(s)){
        printf("Stack is empty\n");
    }else{
        int val = s->data[s->top];
        s->top--;
        return val;
    }
}

int evaluation_of_postfix(char *postfix){
    struct Stack *operator = (struct Stack *)malloc(sizeof(struct Stack));
    operator->top = -1;
    operator->size  = strlen(postfix);
    operator->data = (int*) malloc(operator->size * sizeof(int));
    int i = 0;
    while(postfix[i] != '\0'){
        if(!isOperator(postfix[i])){
            push1(operator, (int)postfix[i]);
            i++;
        }
        else{
            int a = int_converter(pop1(operator));
            int b = int_converter(pop1(operator));
            int c = calculation(postfix[i], b, a);
            push1(operator, c);
            i++;
        }
    }
    int result = (pop1(operator));
    return result;
}