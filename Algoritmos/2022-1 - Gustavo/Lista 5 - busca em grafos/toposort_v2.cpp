#include<bits/stdc++.h>
using namespace std;
 
class Graph{
    private:
        vector<vector<int>> matrix;
        int numEdges;
        vector<int> Mark;
    public:
        Graph(int tam){
            this->matrix = vector<vector<int>>(tam);
            this->numEdges = tam;
            vector<int> Mark(numEdges, 0);
            this->Mark = Mark;
        }
        void addEdge(int a,int b){
            matrix[a].push_back(b);
        }

        void toposort(){

            vector<int> quequeOrder;
            for (int u = 0; u < numEdges; u++){
                for (auto x: matrix[u])
                    Mark[x]++;
            }

            multiset<int> setAux;
            for (int i = 0; i < numEdges; i++){
                if (Mark[i] == 0)
                    setAux.insert(i);
            }

            int cnt = 0;

            while (!setAux.empty()){
                //Pegando o primeiro item do set e pondo-o na lista/fila/stack (toposort se comporta como uma stack, mas quei ficou melhor com lista parecendu uma queue, não julgue)
                int u = *setAux.begin();
                setAux.erase(setAux.begin());
                quequeOrder.push_back(u);
                //Pecorrendo a matriz e verificando se o itens já foram marcados, se sim, inseindo eles na lista
                for (auto x:matrix[u]){
                    if (--Mark[x] == 0)
                        setAux.insert(x);
                }
                cnt++;
            }

            if (cnt != numEdges) {
                cout << "Sandro fails."<<endl;
                return;
            }

            for (int i = 0; i < quequeOrder.size(); i++){
                cout << quequeOrder[i]+1<< " ";
            }
            cout << endl;
        }
};

int main(){
  int tam, imp, a, b;
  cin >> tam >> imp;
  Graph graph = Graph(tam);
  for (int i = 0; i < imp; i++){
    cin >> a >> b;
    a--; b--;
    graph.addEdge(a,b);
  }
  graph.toposort();
  return 0;
}