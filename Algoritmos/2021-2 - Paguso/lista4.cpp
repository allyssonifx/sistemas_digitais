#include <iostream>
#include <string>

struct Node{
    int valor;
    Node* proximo;
};

//Funcao para criar um novo No e inserir ele no historico ou na fila de salvos
Node* list_insert(Node* posicao, int valor){

    //Criacao de um novo No e preenchimento do campo pagina desse No
    Node* temp = new Node();
    temp->valor = valor;

    //Fazendo com que o ponteiro do novo No aponte para o mesmo No que o outro ponteiro de outro No
    temp->proximo = posicao->proximo;

    //Fazendo com que o ponteiro desse outro No aponte para o novo No
    posicao->proximo = temp;

    //Retornando o outro No, com as suas modificacoes
    return posicao;
}

//Funcao para apagar um No do historico ou da fila de salvos, que recebera o head da pilha ou fila
Node* list_delete(Node* posicao){

    //Criando um novo No temporario que vai ter as informacoes do No que queremos deletar
    Node* temp = posicao->proximo;

    if(posicao->proximo != nullptr){
        //Ligamos o No que estava 'atras' do No que deletaremos ao No que estava na 'frente' do deletado
        posicao->proximo = temp->proximo;
        //Campo pagina do head vai receber o campo pagina do No deletado
        posicao->valor = temp->valor;
    }

    //Deletamos o No
    delete temp;

    //Retornamos o head atualizado
    return posicao;
}

int achar_caminho(int** matriz, Node* head, Node* inicio){
    Node* cur = inicio;
    int quantidade = 0;

    while(cur != nullptr){
        if(matriz[head->valor][cur->valor] == 1){
            quantidade++;
        }

        cur = cur->proximo;
    }

    delete [] cur;
    return quantidade;
}

int* criar_kclique(int** matriz, int vertices, int kclique){
    Node* head = new Node();
    int quantidade = 0;
    int qligacoes = 0;
    int* elementos = new int[kclique];
    Node* cur;

    for(int i = 0; i < vertices; i++){
        if(matriz[i][vertices] >= kclique - 1){
            quantidade++;
            head = list_insert(head, i);
        }
    }

    while(quantidade > kclique){
        cur = head->proximo;
        while(cur != nullptr) {
            qligacoes = achar_caminho(matriz, cur, head->proximo);

            if(qligacoes < kclique - 1){
                cur = list_delete(cur);
                quantidade--;
            }

            cur = cur->proximo;
        }
    }

    cur = head->proximo;
    
    for(int i = kclique - 1; i >= 0; i--){
        elementos[i] = cur->valor;
        cur = cur->proximo;
    }

    delete [] head;
    delete [] cur;
    return elementos;
}

int** criar_matriz(int vertices, int kclique){
    char numero;
    int** matriz_temp = new int*[vertices];

    for(int i = 0; i < vertices; i++){
        matriz_temp[i] = new int[vertices + 1];
        matriz_temp[i][i] = 0;
        matriz_temp[i][vertices] = 0;

        for(int j = 0; j < i; j++){
            std::cin >> numero;

            if(numero == '1'){
                matriz_temp[i][j]= 1;
                matriz_temp[i][vertices] += 1;
                matriz_temp[j][i] = 1;
                matriz_temp[j][vertices] += 1;
            }

            else{
                matriz_temp[i][j] = 0;
                matriz_temp[j][i] = 0;
            }
        }
    }

    return matriz_temp;
}

bool verificar_clique(int** matriz, int* kclique, int quantidade){
    for(int i = 0; i < quantidade; i++){
        for(int j = 0; j < quantidade; j++){
            if(matriz[i][j] != 1 && i != j){
                return false;
            }
        }
    }

    return true;
}

int main(int argc, char const *argv[])
{
    int kclique, qagentes, qtentativas, qvertices;

    std::cin >> qagentes >> qvertices >> kclique >> qtentativas;

    int** matriz = new int*[qvertices];

    for(int i = 0; i < qvertices; i++){
        matriz[i] = new int[qvertices];
    }

    int** cliques = new int*[qagentes];

    for(int i = 0; i < qagentes; i++){
        cliques[i] = nullptr;
    }
    int id1, id2;

    for(int i = 0; i < qtentativas; i++){
        int diferentes = 0;
        std::cin >> id1 >> id2;

        if(cliques[id1] == nullptr){
            matriz = criar_matriz(qvertices, kclique);
            cliques[id1] = criar_kclique(matriz, qvertices, kclique);

        }

        if(cliques[id2] == nullptr){
            matriz = criar_matriz(qvertices, kclique);
            
            if(verificar_clique(matriz, cliques[id1], kclique)){
                cliques[id2] = cliques[id1];
            }

            else{
                cliques[id2] = criar_kclique(matriz, qvertices, kclique);
            }

        }

        for(int i = 0; i < kclique; i++){
            if(cliques[id1][i] != cliques[id2][i]){
                diferentes = 1;
                break;
            }
        }

        if(diferentes == 0){
            std::cout << "SUCC";
            for(int i = 0; i < kclique; i++){
                std::cout << " " << cliques[id1][i];
            }
            std::cout << "\n";
        }

        else{
            std::cout << "FAIL\n";
        }

    }

    // for(int i = 0; i < qagentes; i++){
    //     std::cout << i << "\n";
    //     for(int j = 0; j < kclique; j++){
    //         std::cout << " " << cliques[i][j];
    //     }
    //     std::cout << "\n\n";
    // }

    delete [] matriz;
    delete [] cliques;
    return 0;
}
