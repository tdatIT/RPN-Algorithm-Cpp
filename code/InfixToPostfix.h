#include <string>

int isOperand(char ch)
{
    return (ch >= '0' && ch <= '9');
}
int isPriority(char ch)
{
    switch (ch)
    {
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    default:
        return -1;
        break;
    }
}
Queue *infixToPostFix(std::string _infix)
{
    Queue *_postfix = new Queue();
    Stack *_stack = new Stack();
    for (int i = 0; i < _infix.length(); i++)
    {
        if (isOperand(_infix[i]))
            _postfix->push(_infix[i]);
        else if (_infix[i] == '(')
            _stack->push(_infix[i]);
        else if (_infix[i] == ')')
        {
            while (!_stack->isEmpty() && _stack->top() != '(')
            {
                _postfix->push(_stack->top());
                _stack->pop();
            }
            if ((!_stack->isEmpty() && _stack->top() != '('))
                return NULL;
            else
                _stack->pop();
        }
        else
        {
            while (!_stack->isEmpty() &&
                   isPriority(_stack->top()) >= isPriority(_infix[i]))
            {
                _postfix->push(_stack->top());
                _stack->pop();
            }
            _stack->push(_infix[i]);
        }
    }
    while(!_stack->isEmpty()){
        _postfix->push(_stack->top());
        _stack->pop();
    }
    _stack->~Stack();
    return _postfix;
}