


class Stack
{
private:
    ref _node;
    int size = 0;

public:
    Stack();
    ~Stack();
    bool isEmpty();
    int getSize();
    void push(char k);
    char top();
    void pop();
    void print();
};

Stack::Stack()
{
    _node = NULL;
    size = 0;
}

Stack::~Stack()
{
    while(!isEmpty()){
        ref p = _node;
        _node = _node->next;
        delete p;
    }
}
bool Stack::isEmpty()
{
    if (_node == NULL)
    {
        return true;
    }
    return false;
}
int Stack::getSize()
{
    return size;
}
void Stack::push(char k)
{
    if (_node == NULL)
    {
        _node = createNewNode(k);
    }
    else
    {
        ref p = createNewNode(k);
        p->next = _node;
        _node = p;
    }
    size++;
}
void Stack::pop()
{
    if (!isEmpty())
    {
        ref p = _node;
        _node = _node->next;
        delete p;
        size--;
    }
    else
    {
        std::cout << "Stack empty";
    }
}
char Stack::top()
{
    return _node->value;
}
void Stack::print()
{
    while (!isEmpty())
    {
        std::cout << _node->value << " ";
        _node = _node->next;
    }
}
