#include <stdio.h>
#include <assert.h>

struct Node
{
    int data;
    Node* pNext;
    Node* pPrev;
};

class List {
    
    public:
    
    Node* pHead = nullptr;

    void push_back(int data) {

        Node* pNewNode = new Node { data, nullptr, nullptr };

        if ( this->pHead == nullptr ) {
            this->pHead = pNewNode;
            return;
        }

        Node* pCurrentNode = this->pHead;

        while (pCurrentNode->pNext != nullptr)
        {
            pCurrentNode = pCurrentNode->pNext;
        }
        
        pNewNode->pPrev = pCurrentNode;
        pCurrentNode->pNext = pNewNode;

    }

    void push_front(int data) {

        Node* pNewNode = new Node { data, nullptr, nullptr };

        if( pHead == nullptr ){
            this->pHead = pNewNode;
            return;
        }

        pHead->pPrev = pNewNode;
        pNewNode->pNext = pHead;
        this->pHead = pNewNode;

    }

    void push_on(int position, int data) {
        
        int counter = 0;
        Node* pCurrentNode = this->pHead;
        
        while ( counter != position && pCurrentNode->pNext != nullptr )
        {
            counter++;
            pCurrentNode = pCurrentNode->pNext;
        }

        Node* pNewNode = new Node();
        pNewNode->data = data;
        pNewNode->pPrev = pCurrentNode->pPrev;
        pNewNode->pNext = pCurrentNode;
        if( counter == position ) {
            pCurrentNode->pPrev->pNext = pNewNode;
            pCurrentNode->pPrev = pNewNode;
            return;
        }

    }

    void pop_front() {
        Node* oldHead = this->pHead;
        this->pHead = this->pHead->pNext;
        this->pHead->pPrev = nullptr;
        delete oldHead;
    }

    void pop_back() {
        Node* pCurrentNode = this->pHead;
        while (pCurrentNode->pNext != nullptr)
        {
            pCurrentNode = pCurrentNode->pNext;
        }
        pCurrentNode->pPrev->pNext = nullptr;
        delete pCurrentNode;
    } 

    void pop_on(int position) {
        
        int counter = 0;
        Node* pCurrentNode = this->pHead;
        
        while (counter != position || pCurrentNode->pNext == nullptr)
        {
            counter++;
            pCurrentNode = pCurrentNode->pNext;
        }

        if(counter == position) {
            pCurrentNode->pPrev->pNext = pCurrentNode->pNext;
            pCurrentNode->pNext->pPrev = pCurrentNode->pPrev;
            delete pCurrentNode;
        }

    }

    void print() {
        
        if( this->pHead == nullptr ){
            printf("List is empty. \n");
            return;
        }

        Node* pCurrentNode = this->pHead;
        while ( pCurrentNode != nullptr )
        {
            printf("%d ", pCurrentNode->data );
            pCurrentNode = pCurrentNode->pNext;
        }
        printf("\n");

    }

    bool has (int value) {

        Node* pCurrentNode = this->pHead;
        while ( pCurrentNode != nullptr )
        {
            if ( pCurrentNode->data == value ) return true;
            pCurrentNode = pCurrentNode->pNext;
        }
        return false;
        
    }

    Node* find(int value) {
        
        Node* pCurrentNode = this->pHead;

        while (pCurrentNode->data != value && pCurrentNode->pNext != nullptr )
        {
            pCurrentNode = pCurrentNode->pNext;
        }

        if( pCurrentNode->data == value ) return pCurrentNode;

        printf("Value %d not found on list. ", value);

        return nullptr;

    }

    Node* find_on(int position) {
        
        Node* currentNode = this->pHead;
        int counter = 0;

        while ( currentNode->pNext != nullptr && counter != position )
        {
            currentNode = currentNode->pNext;
            counter++;
        }

        if (counter == position)
        {
            return currentNode;
        }
        
        
        printf("List do not have any value on %dth index.", position );

        return nullptr;
    }

};


int main() {

    List list;

    list.print();

    list.push_front(0);

    list.push_back(5);
    list.push_back(10);
    list.push_back(15);

    list.push_front(-5);
    list.push_front(-10);
    list.push_front(-15);

    list.print();

    printf("%d \n", list.has(0));

    printf("%d \n", list.has(4));

    printf("%d \n", list.find(23));

    printf("%d \n", list.find(5));

    list.pop_front();
    list.pop_back();

    list.find_on(3);
    list.find_on(45);

    list.push_on(2, 3);
    list.pop_on(2);

    return 0;
}