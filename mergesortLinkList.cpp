#include <iostream>

using namespace std;

typedef double Elemtype;
typedef struct Node
{
    int val;
    struct Node *next;
} Node, *Linklist;

Linklist CreateLinklist_Tail(Linklist L, int n)
{
    Linklist s, tail;
    L->next = NULL;
    tail = L;

    for (int i = 0; i < n; i++)
    {
        s = new Node;
        cin >> s->val;
        tail->next = s;
        tail = s;
    }
    L = L->next;
    tail->next = NULL;

    return L;
}

void printLinklist(Linklist L)
{
    Linklist p = L;
    while (p->next->next != NULL)
    {
        cout << p->next->val << " ";
        p = p->next;
    }
    cout << p->next->val;
}

void Insert(Linklist L, int pos, Elemtype e)
{
    Linklist p, s;
    int j = 1;
    p = L;
    while (j < pos)
    {
        p = p->next;
        j++;
    }
    s = new Node;
    s->val = e;
    s->next = p->next;
    p->next = s;
}

Elemtype Delete(Linklist L, int pos)
{
    Linklist p, q;
    Elemtype e;
    int j = 1;
    p = L;
    while (j < pos)
    {
        p = p->next;
        j++;
    }
    q = p->next;
    e = q->val;
    p->next = q->next;
    delete q;
    return e;
}

Linklist merge(Linklist node1, Linklist node2)
{
    Linklist dummy = new Node;
    Linklist node = dummy;
    while (node1 && node2)
    {
        if (node1->val < node2->val)
        {
            node->next = node1;
            node1 = node1->next;
        }
        else
        {
            node->next = node2;
            node2 = node2->next;
        }
        node = node->next;
    }
    if (node1)
        node->next = node1;
    if (node2)
        node->next = node2;
    return dummy->next;
}

Linklist MergeSort(Linklist head)
{
    if (!head || !head->next)
        return head;
    Linklist slow = head, fast = head->next;
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Linklist left, right;
    left = head;
    right = slow->next;
    slow->next = NULL;

    left = MergeSort(left);
    right = MergeSort(right);

    return merge(left, right);
}

int main()
{
    Linklist L = new Node;
    CreateLinklist_Tail(L, 5);
    Insert(L, 5, 6);
    cout << Delete(L, 5) << endl;
    MergeSort(L);
    printLinklist(L);
    cout << endl;
    system("pause");
    return 0;
}