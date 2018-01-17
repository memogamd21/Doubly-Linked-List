#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H


class Doublylinkedlist
{
    public:
        Doublylinkedlist();
        struct Node{
        Node* prev;
        int data;
        Node* next;
            };
        struct DLinkList{
        Node* head;
        Node* tail;
        int size;
            };
        DLinkList* createlist();
        DLinkList* insertatLast(DLinkList* g, int u);
        DLinkList* insertAtIndex(DLinkList* J, int n, int data);
        bool isEmpty(DLinkList* O);
        DLinkList* deletefromIndex(DLinkList* L, int index);
        DLinkList* deletefromLast(DLinkList* M);
        bool isFull(DLinkList* Y);
    protected:

    private:
};

#endif // DOUBLYLINKEDLIST_H
