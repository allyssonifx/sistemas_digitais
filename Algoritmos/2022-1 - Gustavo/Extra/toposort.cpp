#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define endl "\n"


class Graph
{ 
public:
    int mark[100000];

    int setMark(int v, int comand){return mark[v] = comand;}

    int getMark(int v){return mark[v];}

    void traverse(vector <vector <int>> &g, int sizeG, stack <int> &s){
        
        for(int v = 0  ; v < sizeG ; ++v){
            setMark(v, 0);
        }

        for(int v = 0; v < sizeG ; ++v){
            if (getMark(v) == 0){
                toposort(g, v, s, sizeG);
            }
        }
    }

    void toposort(vector <vector <int>> &g, int v, stack <int> &s, int size){ // ORDENAÇÃO TOPOLÓGICA
        setMark(v, 1);
        for(int i = 0; i < g[v].size() ; ++i){
            if(getMark(g[v][i]) == 0){
                toposort(g, g[v][i], s, size);
            }
        }
        s.push(v);
    }
};

int main()
{   
    //ios_base::sync_with_stdio(false); 
    //cin.tie(NULL);

    Graph gp = Graph();
    
    int M, N;
    int a, b;


    cin >> M >> N;

    vector < vector < int > > graph(M);
    stack < int > s;

    for(int i = 0; i < N; ++i){ // CRIAÇÃO DO GRAFO
        cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
    }

    gp.traverse(graph, M, s); // TRAVESSIA

    for(int i = 0 ; i < M; ++i){ // PRINT DA PILHA
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}