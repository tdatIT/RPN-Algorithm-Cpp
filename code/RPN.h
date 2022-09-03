#include <cmath>
#include <climits>

float parseInt(char ch)
{
    int value = ch;
    return float(value - '0');
}
char parseChar(int ch)
{
    char value = ch;
    return float(value + '0');
}
int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    return -1;
}

int operation(int a, int b, char op)
{
    // Perform operation
    if (op == '+')
        return b + a;
    else if (op == '-')
        return b - a;
    else if (op == '*')
        return b * a;
    else if (op == '/')
        return b / a;
    else if (op == '^')
        return pow(b, a); // find b^a
    else
        return INT_MIN; // return negative infinity
}
float calculatorRPN(Queue *q)
{
    Stack *s = new Stack();
    while (!q->isEmpty())
    {
        char ch = q->top();
        if (isOperator(ch))
        {
            int a = parseInt(s->top());
            s->pop();
            int b = parseInt(s->top());
            s->pop();
            char sln = operation(a, b, ch) + '0';
            s->push(sln);
        }
        else
        {
            s->push(ch);
        }
        q->pop();
    }
}