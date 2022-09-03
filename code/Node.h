typedef struct node *ref;
struct node
{
    char value;
    node *next;
};
ref createNewNode(char k)
{
    ref p = new node;
    p->value = k;
    p->next = nullptr;
}