#include<bits/stdc++.h>
using namespace std;

class No {
    public:
        char element;
        No *next;

        No(const char& elemento, No* nextno = NULL) {
            element = elemento;
            next = nextno;
        }

        No(No* nextno = NULL){
            next = nextno;
        }
};

class Lista {
    private:
        No *head; // Cabeça ou inicio do ponteiro
        No *tail; // Cauda/ fim do ponteiro
        No *curr;// Cursor, onde o ponteiro está atualmente
        int listam;
public:
        Lista(){ 
            curr = tail = head = new No;
            listam = 0;
        }

        void insert(const char& element){
            curr->next = new No(element, curr->next);
            if (tail == curr){
                tail = curr->next;
            }
            listam++;
        }
        void insert_ini(){
            curr = head;
            }
        void insert_end(){
            curr = tail;
        }
        void next(){ if (curr != tail) curr = curr->next; }

        void printlist(){
            curr = head;
            while (curr != NULL){
                if (curr != head){
                    cout << curr->element;
                }
                curr = curr->next;
                }
            cout << '\n';
        }
        void eraselist(){ 
            while(head != NULL){
                curr = head;
                head = head->next;
                delete curr;
            }
            curr = head = tail = new No;
            listam = 0;
        }

};

int main(){
    char a;
    Lista lista;
    while(scanf("%c",&a) != EOF){      
            if(a == '['){
                lista.insert_ini();
            } else if (a == ']'){
                lista.insert_end();
            } else if (a == '\n'){
                lista.printlist();
                lista.eraselist();
            }else {
                lista.insert(a);
                lista.next();
            }
        
    }
    return 0;
}