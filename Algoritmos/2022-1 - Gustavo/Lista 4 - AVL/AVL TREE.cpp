#include <iostream>
using namespace std;

class AVLNode{
   public:
        int key; // valor
        AVLNode* right; // no direito
        AVLNode* left; // no esquerdo
        int leftF; // peso ou valor do no à equerda
        int rightF;// peso ou valor do no à direita
        int height; // altura da árvore

    
    AVLNode* create_node(int k){ // Função para criar o node
        AVLNode* no = new AVLNode(); // Alocaão para um nó
        no->key = k; // Valor do no
        no->left = NULL; // No a esquerda
        no->right = NULL; // No de 
        leftF = 0; // fator à esquerda
        rightF = 0;  // fator à direita
        height = 0; // altura da árvore


      return no; // retornar o no
    }

     int h(AVLNode *rt){ // Função para retornar tamanho da árvore
        if (rt == NULL){ // Se possuir valor NULL ele é uma folha
          return -1; // então retorne -1
        }
        return rt->height; // Caso não etorne o valor que possui
    }

    int getBalance(AVLNode *rt){// Função que retorna o valor do balanceamento
        if (rt == NULL){ // Se o nó for nulo
            return 0; // retorne 0
        }
        return h(rt->left) - h(rt->right); // Caso ão retornar o valor da esqierda - o da direita
    }
    int findhelp(AVLNode *rt, int key){ // Função para buscar uma chave nas árvor
        if (rt == NULL){ // Se  o nó for nulo retorne um valor absurdo
            return -4000000;
        }
        if (rt->key > key){ // Caso a cahve que eu busco seja menor que a chave que eu estou:
            return findhelp(rt->left, key); // Procuro à esquerda
        }else if(rt->key == key){ // Se o tem que busco é a chave desejada:
            return 1 + rt->leftF; // Retorno o index fo elemento somando 1 ano elemento à esquerda
        }else{ // Caso não
            return 1 + rt->leftF + findhelp(rt->right , key); // Retorno 1 + elemento a esquerda + procura novamente, mas para a direita
        }
    }

    AVLNode* inserthelp(AVLNode *rt, int key){ // Função para inerção
        if (rt == NULL){ // Se a raíz for nula
            return create_node(key); // crie um novo nó com essa chave
        }
        if (rt->key > key){ // Se o eleento da raíz for maior que o elemento a ser inserido:
            rt->left = inserthelp(rt->left, key); // Trasnfiro a inserção para o próximo nó
            rt->leftF++; // Aumento o peso à esquerda
            
        }else{ // Caso não
            rt->right = inserthelp(rt->right, key); // Trasnfira a inserção para o próximo nó à direita
            rt->rightF++; // Aumento o peso à direita
        }

        // PARTE DA AVL -> Balanceamentos
        rt->height = 1 + max(h(rt->left), h(rt->right)); // Tamanho da árvore

        
        int balance = getBalance(rt); //Receber o valor do balanceamento

        if (balance < -1 && key >= rt->right->key){ // Se o balanceamento estiver pesado para a direita em 1 unidade
            return  LR(rt); // rotação à esquerda
        }
        if (balance > 1 && key < rt->left->key){  // Se o balanceamento estiver pesado para a esquerda em 1 unidade
            return RT(rt); // rotação à direita
        }
        if (balance > 1 && key >= rt->left->key){  // Se o balanceamento estiver pesado para a direita  acima de 1 unidade, ou seja com uma bifurc..
            rt->left = LR(rt->left); // rotação para esquerda
            return RT(rt); // rotação à direita
        }
        if (balance < -1 && key < rt->right->key){// Se o balanceamento estiver pesado para a esquerda  acima de 1 unidade, ou seja com uma bifurc..
            rt->right = RT(rt->right); // rotação à direita
            return LR(rt); // rotação à esquerda
        }


        return rt; //retorne o novo no
    }


    int findSon(AVLNode *rt){ // encontrar fator de balanceamento
        if(rt == NULL){return 0;}
        return 1 + rt->leftF + rt->rightF;

    } 



    AVLNode* RT(AVLNode *rt){
        AVLNode* l = rt->left; //colocando o nó á esquerda como l
        AVLNode* lr = l->right;//colocando o nó direita como lr

        l->right = rt; //o no à esquerda da esquerda agora será o da direita
        rt->left = lr; // o no à direita agora será o da esquerda

        // Atualizando a altura
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        l->height = max(h(l->left), h(l->right)) + 1;

        // Atualizando os novos valoreas
        rt->leftF = findSon(rt->left);
        rt->rightF = findSon(rt->right);

        l->rightF = findSon(l->right);
        l->leftF = findSon(l->left);

        return l;
    }

    AVLNode* LR(AVLNode *rt){
        AVLNode* r = rt->right;
        AVLNode* rl = r->left;

        r->left = rt;
        rt->right = rl;
        rt->height = max(h(rt->left), h(rt->right)) + 1;
        r->height = max(h(r->left), h(r->right)) + 1;

        rt->leftF = findSon(rt->left);
        rt->rightF = findSon(rt->right);
        
        r->leftF = findSon(r->left);
        r->rightF = findSon(r->right);

        return r;
    }  

};


int main(){
    int Q, C;
    long int X;

    int ans;

    AVLNode bst = AVLNode();
    bool firstR = true;
    AVLNode *root;

    cin >> Q;

    for(int i = 0; i < Q; ++i){

        cin >> C >> X;

        if(C == 1 && firstR){
            root = bst.create_node(X);
            firstR = false;
        }else if(C == 1){
            root = bst.inserthelp(root, X);
        }else{
            ans = bst.findhelp(root, X);
            if (ans < 0){
                cout << "Data tidak ada" << "\n";
            }else{
                cout << ans << "\n";
            }
        }
    }

    return 0;
}