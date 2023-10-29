#include <iostream>
#include <string>

struct No
{
    int distancia;
    int vertice;
};


//Funcao para montar a matriz
int** montar_matriz(int qvertices){
    int** matriz = new int*[qvertices];
    int quantidade, indice, largura;

    //Loop para montar cada linha
    for(int j = 0; j < qvertices; j++){
        matriz[j] = new int[qvertices];

        for(int i = 0; i < qvertices; i++){
            matriz[j][i] = 0;
        }

        //Pegando a quantidade de ligacoes daquele no
        std::cin >> quantidade;
        
        //Pegando e calculando o custo
        for(int i = 0; i < quantidade; i++){
            std::cin >> indice >> largura;

            matriz[j][indice] = int((1<<20)/largura);        
        }
    }

    // for(int i = 0; i < qvertices; i++){
    //     for(int j = 0; j < qvertices; j++){
    //         std::cout << matriz[i][j] << " ";
    //     }
    //     std::cout << "\n";
    // }

    return matriz;
}

No* bubble_up(No* heap, int posicao, int* visitados){
    int i = posicao;

    while(i > 0 && (heap[i].distancia <= heap[int((i-1)/2)].distancia)){
        int distancia, vertice;
        distancia = heap[i].distancia;
        vertice = heap[i].vertice;

        heap[i].distancia = heap[int((i-1)/2)].distancia;
        heap[i].vertice = heap[int((i-1)/2)].vertice;

        heap[int((i-1)/2)].distancia = distancia;
        heap[int((i-1)/2)].vertice = vertice;

        visitados[heap[int((i-1)/2)].vertice] = int((i-1)/2);
        visitados[heap[i].vertice] = i;
        

        i = int((i-1)/2);
    }


    return heap;
}

No* heap_insert(No* heap, int distancia, int vertice, int quantidade, int* visitados){

    heap[quantidade].vertice = vertice;
    heap[quantidade].distancia = distancia;
    visitados[vertice] = 0;

    if(quantidade > 0){
        visitados[vertice] = quantidade - 1;
        heap = bubble_up(heap, quantidade - 1, visitados);
    }

    return heap;
}

No* bubble_down(No* heap, int posicao, int quantidade, int* visitados){
    int l, r, m;
    l = (2*posicao) + 1;
    r = (2*posicao) + 2;
    m = posicao;

    if(l < quantidade && heap[l].distancia <= heap[m].distancia){
        m = l;
    }

    if (r < quantidade && heap[r].distancia <= heap[m].distancia){
        m = r;
    }

    if(m != posicao){
        int distancia, vertice;
        distancia = heap[m].distancia;
        vertice = heap[m].vertice;

        heap[m].distancia = heap[posicao].distancia;
        heap[m].vertice = heap[posicao].vertice;

        heap[posicao].distancia = distancia;
        heap[posicao].vertice = vertice;

        visitados[heap[posicao].vertice] = posicao;
        visitados[heap[m].vertice] = m;

        return bubble_down(heap, m, quantidade, visitados);
    }

    return heap;
}

No* heap_extract(No* heap, int quantidade, int* visitados){
    No* excluido = new No();
    excluido->distancia= heap[0].distancia;
    excluido->vertice = heap[0].vertice;
    visitados[heap[0].vertice] = 0;

    if(quantidade > 0){
        heap[0].distancia = heap[quantidade - 1].distancia;
        heap[0].vertice = heap[quantidade - 1].vertice;


        heap[quantidade - 1].distancia = excluido->distancia;
        heap[quantidade - 1].vertice = excluido->vertice;

        visitados[heap[quantidade - 1].vertice] = quantidade - 1;

        quantidade--;

        heap = bubble_down(heap, 0, quantidade, visitados);
    }

    return excluido;
}

No* heap_update(No* heap, int* visitados, int vertice, int distancia, int* quantidade){
    if(visitados[vertice] >= 0){
        heap[visitados[vertice]].distancia = distancia;
        heap = bubble_up(heap, visitados[vertice], visitados);
    }

    else{
        heap = heap_insert(heap, distancia, vertice, *quantidade, visitados);
        *quantidade += 1;
    }

    return heap;
}

void Dijkstra(int** matriz, int qvertices, int S, int* Distancia, int* Precursor){
    int quantidade = 0;
    No* retirado;
    int* visitados = new int[qvertices];

    for(int i = 0; i < qvertices; i++){
        Distancia[i] = 1000000000;
        Precursor[i] = -1;
        visitados[i] = -1;
    }

    Distancia[S] = 0;
    visitados[S] = 0;

    No* heap = new No[qvertices];

    heap = heap_insert(heap, Distancia[S], S, 0, visitados);
    quantidade++;

    for(int i = 0; i < qvertices; i++){

        retirado = heap_extract(heap, quantidade, visitados);
        quantidade--;

        int* adjacencia = matriz[retirado->vertice];


        for(int j = 0; j < qvertices; j++){
            if(Distancia[retirado->vertice] + adjacencia[j] < Distancia[j] && adjacencia[j] != 0) {

                Distancia[j] = Distancia[retirado->vertice] + adjacencia[j];
                Precursor[j] = retirado->vertice;

                heap = heap_update(heap, visitados, j, Distancia[j], &quantidade);

            }
        }
    }

    delete [] heap;
}

//Funcao main
int main(int argc, char const *argv[])
{
    std::string teste;
    //qtestes = quantidade de testes;
    //qvertices = tamanho da matriz
    //dr = roteador designado
    //qmensagem = quantidade de mensagens
    int qtestes, qvertices, dr;
    int** matriz;
    int emissor, receptor, qmensagem;
    float tamanho;

    int* Distancia;
    int* Precursor;

    int quantidade, soma, vertice;

    std::cin >> qtestes;

    //Loop para realizar cada teste
    for(int i = 0; i < qtestes; i++){
        std::cin >> qvertices >> dr;

        Distancia = new int[qvertices];
        Precursor = new int[qvertices];

        matriz = montar_matriz(qvertices);

        std::cin >> qmensagem;

        std::cout << "caso " << i << ":\n";
        Dijkstra(matriz, qvertices, dr, Distancia, Precursor);

        //Loop para cada mensagem
        for(int j = 0; j < qmensagem; j++){
            std::cin >> emissor >> receptor >> tamanho;


            soma = Distancia[receptor] + Distancia[emissor];
            quantidade = 0;
            vertice = emissor;

            while(vertice != dr){
                quantidade += 1;
                vertice = Precursor[vertice];
            }

            vertice = receptor;

            while(vertice != dr){
                quantidade += 1;
                vertice = Precursor[vertice];
            }

            std::cout << quantidade << " " << int((soma*tamanho)/int(1 << 20)) << "\n";

        }

        std::cout << "\n";

        // std::cin;
        delete [] matriz;
        delete [] Distancia;
        delete [] Precursor;
    }

    return 0;
}
