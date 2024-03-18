#include <stdio.h>

struct Node {
    int data;
    Node * next;
    Node * prev;
};

struct LinkedList
{
    Node * head = nullptr;
};

void push( LinkedList * pLinkedList, int data ) {
    
    Node newNode;
    newNode.data = data;
    newNode.next = nullptr;

    if( pLinkedList->head == nullptr ) {
        pLinkedList->head = &newNode; 
        return;
    }
    
    Node * currentNode = pLinkedList->head;

    while (currentNode != nullptr)
    {
        currentNode = currentNode->next;
    }

    currentNode->next = &newNode;
    
}

void print_list(LinkedList * list){
    Node * currentNode = list->head;

    while (currentNode != nullptr)
    {
        printf("%d ",currentNode->data);
        printf("\n");
        currentNode = currentNode->next;
    }
}


int main() {

    LinkedList newLinkedList;

    push(&newLinkedList,5);

    print_list(&newLinkedList);

    return 0;
}