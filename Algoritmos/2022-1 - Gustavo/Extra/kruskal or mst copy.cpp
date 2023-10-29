#include <bits/stdc++.h>
using namespace std;

class Graph{
    public:
        vector < pair < int, pair< int, int > > >  graph;

        void insert(int u, int v, int w) {
            this->graph.push_back({w,{u,v}});
        }
        
        vector <int> haepTravel(){
            sort(this->graph.begin(), this->graph.end());
        }

};


int find(int curr, vector < int > &aux){
    if (aux[curr] == curr){
        return curr;
    }
    return aux[curr] = find(aux[curr], aux);
}



int main(){

    int n, m;


    while (cin >> n >> m && (m > 0 && n > 0)){
        if(m != 0){
            vector < pair < int, pair< int, int > > >  g;
            int u, v, w;
            
            for(int i = 0; i < m; ++i){
                cin >> u >> v >> w;
                g.push_back({w, {u, v}});
            }

            sort(g.begin(), g.end());

            vector < int > aux;

            for(int i = 0; i < n; ++i){
                aux.push_back(i);
            }

            vector < int > ans;

            for(int x = 0; x < g.size(); ++x){
                int weight, vexter1, vexter2, c1, c2;
                
                vexter1 = g[x].second.first;
                vexter2 = g[x].second.second;
                weight = g[x].first;

                c1 = find(vexter1, aux);
                c2 = find(vexter2, aux);

                if(c1 != c2){
                    aux[c2] = c1;
                }else{
                    ans.push_back(weight);
                }

                
            }

            if(ans.empty()) {
                cout << "forest\n";
            }else{
                sort(ans.begin(), ans.end());
                for(int i = 0; i < ans.size(); ++i){

                    if (i==0){
                        cout << ans[i];
                    }else{
                        cout << " " << ans[i];
                    }
                }
                cout << "\n";
            }
        }else{
            cout << "forest\n";
        }
    }
    return 0;
}