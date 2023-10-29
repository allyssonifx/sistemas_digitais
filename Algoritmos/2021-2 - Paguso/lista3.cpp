#include <iostream>
#include <string>

struct AVL{
    int identificador;
    int bf;
    int soma;
    int quantidade_pacotes;
    AVL* esquerda;
    AVL* direita;
};

AVL* Rotate_left(AVL* root){

    AVL* R = root->direita;
    AVL* RL = R->esquerda;
    R->esquerda = root;
    root->direita = RL;
    R->soma = root->quantidade_pacotes + root->soma + R->soma;

    if(R->bf <= 0){
        root->bf = root->bf - 1;
    }

    else{
        root->bf = root->bf - 1 - R->bf;
    }

    if(root->bf >= 0){
        R->bf = R->bf - 1;
    }

    else{
        R->bf = R->bf - 1 + root->bf;
    }

    return R;
}

AVL* Rotate_right(AVL* root){

    AVL* R = root->esquerda;
    AVL* RD = R->direita;
    R->direita = root;
    root->esquerda = RD;
    root->soma -= R->soma + R->quantidade_pacotes;

    if(R->bf >= 0){
        root->bf += 1;
    }

    else{
        root->bf = root->bf + 1 - R->bf;
    }

    if(root->bf <= 0){
        R->bf += 1;
    }

    else{
        R->bf += 1 + root->bf;
    }

    return R;
}

AVL* insert(AVL* root, int identificador, int* Hc,int quantidade, int soma){
    if(root == nullptr){
        AVL* novo = new AVL();
        novo->esquerda = nullptr;
        novo->direita = nullptr;
        novo->identificador = identificador;
        novo->bf = 0;
        novo->quantidade_pacotes = quantidade;
        novo->soma = soma;

        *Hc = 1;
        return novo;
    }

    else if(identificador == root->identificador){
        root->quantidade_pacotes += quantidade;

        *Hc = 0;
        return root;
    }

    else if(identificador < root->identificador){
        root->soma += quantidade;
        root->esquerda = insert(root->esquerda, identificador, Hc, quantidade, soma);

        root->bf -= *Hc;
    }

    else{
        root->direita = insert(root->direita, identificador, Hc, quantidade, soma);
        root->bf += *Hc;
    }

    if(*Hc == 0){
        return root;
    }

    else if(root->bf == 0){
        *Hc = 0;
        return root;
    }

    else if(abs(root->bf) == 1){
        *Hc = 1;
        return root;
    }

    else if(root->bf == -2){
        if(root->esquerda->bf == 1){
            root->esquerda = Rotate_left(root->esquerda);
        }

        *Hc = 0;
        return Rotate_right(root);
    }

    else{
        if(root->direita->bf == -1){
            root->direita = Rotate_right(root->direita);
        }

        *Hc = 0;
        return Rotate_left(root);
    }
}

AVL* RNK(AVL* root, int indice, int* soma){

    if(root == nullptr){
        return root;
    }

    else if(indice == root->identificador){
        *soma += root->soma;
        return root;
    }

    else if(indice < root->identificador){
        return RNK(root->esquerda, indice, soma);
    }

    else if(indice > root->identificador) {
        *soma += root->soma + root->quantidade_pacotes;
        return RNK(root->direita, indice, soma);
    }

    else{
        return root;
    }
}

AVL* WEI(AVL* root, int indice, int* profundidade){

    if(root->esquerda == nullptr && root->direita == nullptr){
        return root;
    }

    else if(indice == root->identificador){
        return root;
    }

    else if(indice < root->identificador && root->esquerda != nullptr){
        *profundidade += 1;
        return WEI(root->esquerda, indice, profundidade);
    }

    else if(indice > root->identificador && root->direita != nullptr) {
        *profundidade += 1;
        return WEI(root->direita, indice, profundidade);
    }

    else{
        return root;
    }
}

int main(int argc, char const *argv[])
{
    AVL* head = nullptr;
    int total = 0;
    int numero;
    int indice;
    int Hc;
    std::string Comando = "";

    while(Comando != "END"){
        Hc = 0;
        std::cin >> Comando;

        if(Comando == "ADD"){
            std::cin >> indice >> numero;
            total += numero;
            head = insert(head, indice, &Hc, numero, 0);
            std::cout << total << "\n";
        }

        else if(Comando == "WEI"){
            int profundidade = 0;
            std::cin >> indice;
            AVL* achado = WEI(head, indice, &profundidade);

            if(achado->identificador != indice){
                std::cout << "0 -1\n";
            }

            else{
                std::cout << achado->quantidade_pacotes << " " << profundidade << "\n";
            }

        }

        else if(Comando == "RNK"){
            int soma = 0;
            std::cin >> indice;
            AVL* achado = RNK(head, indice, &soma);

            std::cout << soma << "\n";

        }
    }
    return 0;
}
