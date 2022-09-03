#include<iostream>

class Queue
{
private:
    ref _node;
    int size;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void push(char ch);
    char top();
    void pop();
    int getSize();
    void print();
};

Queue::Queue()
{
    _node = NULL;
    size = 0;
}
bool Queue::isEmpty()
{
    return (_node == NULL);
}
void Queue::push(char ch)
{
    if (isEmpty())
    {
        _node = createNewNode(ch);
    }
    else
    {
        ref p = _node;
        while (p->next != NULL)
            p = p->next;
        p->next = createNewNode(ch);
    }
    size++;
}
void Queue::pop()
{
    ref p = _node;
    _node = _node->next;
    delete p;
}
char Queue::top()
{
    return _node->value;
}
int Queue::getSize()
{
    return size;
}
void Queue::print(){
    while(!isEmpty()){
        std::cout<<_node->value<<" ";
        _node = _node->next;
    }
}
Queue::~Queue()
{
    while (!isEmpty())
    {
        ref p = _node;
        _node = _node->next;
        delete p;
    }
}
