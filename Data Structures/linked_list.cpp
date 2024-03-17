#include <stdio.h>

// Single_Linked List Node
struct Node {
    int data;
    Node * next;
};

struct LinkedList {
    Node * head;
};

// Traverse all Nodes: O(N)
void print_linked_list(LinkedList list) {
    Node * current_node = list.head;

    while ( current_node != NULL )
    {
        printf("%d ",current_node->data);
        current_node = current_node->next;
    }
    printf("\n");
}

// Insert at first: O(1)
void insert_at_first(LinkedList * p_linkedList, Node * p_newNode) {
    Node * lastHead = p_linkedList->head;
    p_newNode->next = lastHead;
    p_linkedList->head = p_newNode;
}

// Insert at last: O(N)
void insert_at_last(LinkedList * p_linkedList, Node * p_newNode) {
    Node * current_node = p_linkedList->head;
    while (current_node->next != NULL)
    {
        current_node = current_node->next;
    }
    p_newNode->next = NULL;
    current_node->next = p_newNode;
}

// Insert after given: O(1)
void insert_after_given_node(LinkedList * p_linkedList, Node * givenNode, Node * newNode) {
    Node * newNextNode = givenNode->next;
    newNode->next = newNextNode;
    givenNode->next = newNode;
}

// Delete first: O(1)
void delete_first(LinkedList * p_linked_list) {
    p_linked_list->head = p_linked_list->head->next;
}

// Delete last: O(N)
void delete_last(LinkedList * p_linkedList) {
    Node * currentNode = p_linkedList->head;
    while (currentNode->next->next != NULL)
    {
        currentNode = currentNode->next;
    }
    currentNode->next = NULL;    
}

//Delete given: O(N)
void delete_given(LinkedList * LinkedList, Node * given) {
    Node * currentNode = LinkedList->head;
    Node * previousNode;
    while( currentNode != given ) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }
    previousNode->next = currentNode->next;
}

int main(){

    Node nd_a;
    Node nd_b;
    Node nd_c;

    nd_a.data = 10;
    nd_a.next = &nd_b;

    nd_b.data = 20;
    nd_b.next = &nd_c;

    nd_c.data = 30;
    nd_c.next = NULL;

    LinkedList newLinkedList;

    newLinkedList.head = &nd_a;

    print_linked_list(newLinkedList);

    Node nd_alpha;
    nd_alpha.data = 0;

    insert_at_first( &newLinkedList, &nd_alpha );

    print_linked_list(newLinkedList);

    Node nd_d;
    nd_d.data = 40;

    insert_at_last( &newLinkedList, &nd_d );

    print_linked_list(newLinkedList);

    Node nd_ab;
    nd_ab.data = 15;

    insert_after_given_node(&newLinkedList, &nd_a, &nd_ab);

    print_linked_list(newLinkedList);

    delete_first(&newLinkedList);

    print_linked_list(newLinkedList);

    delete_last(&newLinkedList);

    print_linked_list(newLinkedList);

    delete_given(&newLinkedList,&nd_ab);

    print_linked_list(newLinkedList);

    return 0; 
}