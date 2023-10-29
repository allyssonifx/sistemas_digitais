#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        vector < vector < pair <int, int> > > matrix;
        int size;

        Graph(int size){
            // Vetores temporários para deixar no corpo do objeto
            vector < vector < pair <int, int> > > matrix(size+1);
            this->matrix = matrix;
            this->size = size;
        }

        int dijkstra(int initial, int target){
            //Primeira parte do video do slide lá, mas sem usar o for, pois as funções da bits preenche automaticamente
            vector < int > distance(this->size+1, 50001); //50001 é o infinito, já que n haverá nada nas entradas maior que ele
            vector < int > mark(this->size+1, 0);
            priority_queue < pair <int, int > , vector < pair < int, int > > , greater < pair <int, int> > > heap; // Criação que heap min top-down

            distance[initial] = 0;
            heap.push({0, initial});

            int v;
            for (int i = 0; i < this->size; ++i){

                do{
                    if(heap.empty()){ // Caso a heap fique vazia retornamos
                        return distance[target];
                        }
                    v = heap.top().second;
                    heap.pop();
                }while(mark[v] == 1);

                mark[v] = 1;

                for(auto edge : this->matrix[v]){
                    int vertice = edge.second;
                    int weight = edge.first;

                    if (!(mark[vertice]) && distance[vertice] > distance[v] + weight){ //Caso seja melhor pasando por outro vértice, ou obrigatóriamente ele tem que passar pelo vértice
                    distance[vertice] = distance[v] + weight;
                    heap.push({distance[vertice], vertice});
                    }
                }
            }   
            return distance[target]; //Saia caso a heap não esteja vazia quando passou no do while
        }
};


int main(){
    int cases;
    cin >> cases;
    
    for(int i = 0 ; i < cases; ++i){

        int n, m, initial, final;

        cin >> n >> m >> initial >> final;
        Graph graph = Graph(n);
        
        int v1, v2, w; // vertices e o peso
        for(int j = 0; j < m; ++j){

            cin >> v1 >> v2 >> w;

            graph.matrix[v1].push_back({w, v2});
            graph.matrix[v2].push_back({w, v1});

        }

        int dist = graph.dijkstra(initial, final);

        //Prints
        cout << "Case #" << i+1 << ": ";
        if (dist == 50001){
            cout << "unreachable" << endl;
        }else{
            cout << dist << endl;
        }
    }
    return 0;
}