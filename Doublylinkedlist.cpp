#include "Doublylinkedlist.h"
#include <iostream>
#include <stdio.h>

using namespace std;


Doublylinkedlist::DLinkList* Doublylinkedlist::createlist(){
    DLinkList* h = new DLinkList();
    h->head = NULL;
    h->tail = NULL;
    h->size = 0;
    return h;
}
Doublylinkedlist::DLinkList* Doublylinkedlist::insertatLast(DLinkList* g, int u){
    Node* temp = new Node();
    temp->data = u;
    if(g->size == 0){
        g->head = temp;
        g->tail = temp;
        g->size ++;
        return g;
    }else if(g->size == 1){
        g->tail = temp;
        temp->next = g->head;
        temp->prev = g->head;
        g->size ++;
        return g;
    }else{
    temp->next = g->head;
    temp->prev = g->tail;
    g->tail = temp;
    g->size ++;
    return g;
}
}
Doublylinkedlist::DLinkList* Doublylinkedlist::insertAtIndex(DLinkList* J, int n, int data){
    Node* tempnode = new Node();
    tempnode->data = data;
    Node* tempNode = new Node();
    tempNode = J->head;
    for(int i=0; i<n-2; i++){
        tempNode = tempNode->next;
    }
    tempnode->prev = tempNode;
    tempnode->next = tempNode->next;
    tempNode->next = tempnode;
    J->size ++;
    return J;
}
Doublylinkedlist::DLinkList* Doublylinkedlist::deletefromIndex(DLinkList* L, int index){
    Node* temp4 = new Node();
    Node* temp5 = new Node();
    temp4 = L->head;
    if(L->size == 0 || temp4 == NULL){
        return L;
    }else if(L->size == 1 || L->head == L->tail){
        L->head = NULL;
        L->tail = NULL;
        L->size --;
        delete temp4;
        return L;
    }else{
    for(int y=0; y<index-2; y++){
        temp4 = temp4->next;
    }  // we end this loop at the element just before the required element
    temp5 = temp4->next; // temp5 is now the required element to be deleted
    temp4->next = temp5->next; // but first we should modify the links to temp4 to be temp5->next
    temp5->next->prev = temp4; // and the previous of that element must be temp4
    delete temp5;
    L->size --;
    return L;
}
}

Doublylinkedlist::DLinkList* Doublylinkedlist::deletefromLast(DLinkList* M){
    Node* g = new Node();
    if( M->size == 0 ){
        return M;
    }else if (M->size == 1 || M->head == M->tail){
        g = M->tail; // in case there is a single element in the list we set the head and the tail equal to NULL and delete this item
        M->head = NULL;
        M->tail = NULL;
        delete g;
        M->size --;
        return M;
    }else{
    g = M->tail;
    g->prev->next = M->head;
    M->head->prev = g->prev;
    M->tail = g->prev;
    delete g;
    M->size --;
    return M;
}
}

bool Doublylinkedlist::isEmpty(DLinkList* O){
    if (O->size == 0 || (O->head == NULL && O->tail == NULL))
        return true;
    else {
        return false;
    }
}
bool Doublylinkedlist::isFull(DLinkList* Y){
    Node* tempnd = new Node();
    tempnd = Y->head;
    int counter = 1;
    while(tempnd != NULL){
        tempnd = tempnd->next;
        counter ++;      // This counter is incremented as long as we traverse the list and by the end, if it's equal to the size , then the list is full
    }
    if (counter == Y->size){
        return true;
    }else {
        return false;
    }
}
