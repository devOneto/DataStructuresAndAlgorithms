#include <stdio.h>

struct Node {
    int key;
    Node* left = nullptr;
    Node* right = nullptr;
};

class BinarySearchTree {

    public:

        Node* root = nullptr;

        BinarySearchTree( ): root(nullptr) { }

        BinarySearchTree( int key ): root(new Node{ key, nullptr, nullptr }) { }

        Node* insert( int key, Node* from_node = nullptr ) {

            Node* newNode = new Node { key };

            if ( this->root == nullptr ) {
                this->root = newNode;
                return this->root;
            }

            if ( from_node == nullptr ) {
                return newNode;
            }

            if ( key < from_node->key ) {
                from_node->left = this->insert(key, from_node->left);
            }

            if ( key > from_node->key ) {
                from_node->right = this->insert(key, from_node->right);
            }

            return from_node;

        }

        void print_preorder(Node* node) {
            printf("%d ", node->key);
            if( node->left ) this->print_preorder(node->left);
            if ( node->right ) this->print_preorder(node->right);
        }

        void print_inorder(Node* node) {
            if ( node->left ) this->print_inorder(node->left);
            printf("%d ", node->key);
            if ( node->right ) this->print_inorder(node->right);
        }

        void print_posorder(Node* node) {
            if ( node->left ) this->print_posorder(node->left);
            if ( node->right ) this->print_posorder(node->right);
            printf("%d ", node->key);
        }

        Node* find(int key, Node* node) {

            if ( this->root == nullptr ) return nullptr;

            if ( node->key == key ) return node;

            if ( node->left && key <= node->left->key ) {
                return this->find( key, node->left );
            }

            if ( node->right && key >= node->right->key ) {
                return this->find(key, node->right );
            }

            return nullptr;

        }

        Node* remove( int key, Node* from_node ) {           

            if ( this->root == nullptr ) return nullptr;

            if ( key < from_node->key ) {
                from_node->left = this->remove(key, from_node->left);
                return from_node;
            }

            if ( key > from_node->key) {
                from_node->right = this->remove(key, from_node->right);
                return from_node;
            }

            Node* target = from_node;

            // do not have children
            if ( !target->right && !target->left ) {
                delete target;
                return nullptr;
            }
            // have only one child
            if ( !target->left && target->right ) { 
                Node* temp = target->right;
                delete target;
                return temp;
            }
            if ( !target->right && target->left ) {
                Node* temp = target->left;
                delete target;
                return temp;
            }
            // have both children
            if ( target->right && target->left ) {

                Node* temp = this->findMin(target->right); // could be findMax(target->left) too
                target->key = temp->key;
                target->right = this->remove(temp->key, target->right);
            }


            return from_node;

        }

        int getMaxDepth ( Node* from_node ) {
            
            if ( from_node == nullptr ) return 0;

            int leftDepth = this->getMaxDepth(from_node->left);
            int rightDepth = this->getMaxDepth(from_node->right);

            return (leftDepth > rightDepth) ? leftDepth + 1 : rightDepth + 1;

        }

    private:
        
        Node* findMin(Node* from_node) {
            while( from_node->left != nullptr ) {
                from_node = from_node->left;
            }
            return from_node;
        }

        Node* findMax(Node* from_node) {
            while( from_node->right != nullptr ) {
                from_node = from_node->right;
            }
        }

};

int main() {

    BinarySearchTree* bst = new BinarySearchTree();

    bst->insert(16);
    bst->insert(12, bst->root);
    bst->insert(20, bst->root);
    bst->insert(8, bst->root);
    bst->insert(6, bst->root);
    bst->insert(10, bst->root);
    bst->insert(14, bst->root);
    bst->insert(18, bst->root);
    bst->insert(24, bst->root);

    bst->print_preorder(bst->root);
    printf("\n");
    bst->print_inorder(bst->root);
    printf("\n");
    bst->print_posorder(bst->root);
    printf("\n");

    printf("%d ", bst->find(24, bst->root), "\n");

    bst->remove(12, bst->root);

    printf("BST Height: %d", bst->getMaxDepth(bst->root));

    return 0;
}