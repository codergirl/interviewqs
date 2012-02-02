#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;

namespace interview_qs
{

class list
{
private:
    struct node 
    {
        node* next;
        node* prev;
        node* child;
        int data;
        
        node(int data_) : next(NULL), prev(NULL), child(NULL), data(data_)
        {
        }
    };

    node* head;
    node* tail;

public:    
    list()
    {
        head = NULL;
        tail = NULL;      
    }

    void appendNode(int data)
    {
        node* n = new node(data);
        
        if (!tail)
        {
            tail = n;
            head = n;
        }
        else
        {
            n->prev = tail;
            tail->next = n;
            tail = tail->next;
        }
    }

    void appendNode(node* nodetoappend)
    {
        nodetoappend->prev = tail;
        tail->next = nodetoappend;
        tail = tail->next;
    }

    void appendChild(node* n, int data)
    {
        node* newnode = new node(data);
        n->child = newnode;
    }

    void printList()
    {
        node* curr = head;
        while (curr)
        {
            printf("%d\n", curr->data);
            curr = curr->next;
        }
    }

    void createList()
    {
        appendNode(25);
        appendNode(37);
        appendNode(12);
        
        appendChild(head->next, 6);
        appendChild(head->next->child, 12);
        appendChild(head->next->child->child, 16);
        appendChild(head->next->next, 102);
        appendChild(head->next->next->child, 315);
        appendChild(head->next->next->child->child,1224);
    }

    void flattenList()
    {
        node* curr = head;

        while (curr)
        {
            if (curr->child)
            {
                appendNode(curr->child);
            }
            curr = curr->next;
        }
    }
};
}

using namespace interview_qs;

int main(void)
{
    list l;
    l.createList();

    l.flattenList();
    l.printList();
}
