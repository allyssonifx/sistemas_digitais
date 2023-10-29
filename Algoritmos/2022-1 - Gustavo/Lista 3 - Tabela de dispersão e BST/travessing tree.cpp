#include <iostream>
using namespace std;

class Node{
    private:
    Node *left, *rigth;
    int key;

    public:
    Node(int key){
        this->key = key;
        left = NULL;
        rigth = NULL;
    }

    int getKey(){
        return key;
    }

    Node* getLeft(){
        return left;
    }

    Node* getRight(){
        return rigth;
    }

    void setLeft(Node * node){
        left = node;
    }

    void setRight(Node * node){
        rigth = node;
    }

};

class Tree{
    private:
        Node* root;
        int size;
    
    public:
        Tree(){
            root = NULL;
        }
        
        void insert(int key){
            if (root == NULL)
                root = new Node(key);
            else
                insertAux(root, key);
        }

        void insertAux(Node* node, int key){
            if (key < node->getKey()){
                if(node->getLeft() == NULL){
                    Node* new_node = new Node(key);
                    node->setLeft(new_node);
                } else{
                    insertAux(node->getLeft(), key);
                    size++;
                }
            }else if (key >= node->getKey()) {
                if (node->getRight() == NULL){
                    Node* new_node = new Node(key);
                    node->setRight(new_node);
                } else {
                    insertAux(node->getRight(), key);
                    size++;
                }
            }   
        }
        int getSize(){
            return size;
        }

        Node* getRoot(){
            return root;
        }

        void preOrder(Node* node){
            if (node != NULL){
                cout <<" "<<node->getKey();
                preOrder(node->getLeft());
                preOrder(node->getRight());

            }
        }

        void inOrder(Node* node){
            if (node != NULL){
                inOrder(node->getLeft());
                cout <<" "<<node->getKey();
                inOrder(node->getRight());
            }
        }

        void postOrder(Node* node){
            if (node != NULL){
                postOrder(node->getLeft());
                postOrder(node->getRight());
                cout <<" "<<node->getKey();
            }
        }


        void remove(int value, Node* aux=NULL){
            if (aux == NULL){
                aux = root;
                remove(value, aux);
            } else if (value < aux->getKey()){
                remove(value, aux->getLeft());
            } else if (value > aux->getKey()){
                remove(value, aux->getRight());
            } else if (value == aux->getKey()){
                delete aux;
            }else {
                cout << "Error: ";
            }
        }
};

int main(){
    Tree arvore;
    int tam;
    cin >> tam;
    for (int i = 0; i < tam; i++) {
        long long int value;
        cin >> value;
        arvore.insert(value);
    }
    cout << "Pre order :";
    arvore.preOrder(arvore.getRoot());
    cout << "\n";
    cout << "In order  :";
    arvore.inOrder(arvore.getRoot());
    cout << "\n";
    cout << "Post order:";
    arvore.postOrder(arvore.getRoot());
    cout<< "\n";
    return 0;
}