#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

const int INF = 1000000000;



int _dijkstra(vector < vector < pair <int, int> > > &g, int s, int size, int target){
    
    vector < int > distance(size+1, INF);
    vector < int > mark(size+1, 0);

    priority_queue < pair <int, int > , vector < pair < int, int > > , greater < pair <int, int> > > pq; // criação que heap min

    distance[s] = 0;
    pq.push({0, s});
    int v;

    for (int i = 0; i < size; ++i){

        do{
            if(pq.empty()){return distance[target];}
            v = pq.top().second;
            pq.pop();
        }while(mark[v] == 1);

        mark[v] = 1;

        for(auto edge : g[v]){
            int vexter = edge.second;
            int weight = edge.first;

            if (!(mark[vexter]) && distance[vexter] > distance[v] + weight){
            distance[vexter] = distance[v] + weight;
            pq.push({distance[vexter], vexter});
            }
        }
        //  
    }   
    return distance[target];
}


int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);

    int C;
    
    cin >> C;
    
    for(int i = 0 ; i < C; ++i){
        int n, m, startCity, finishCity;
        cin >> n >> m >> startCity >> finishCity;
        vector < vector < pair <int, int> > > g(n+1);
        
        int v1, v2, time;
        for(int x = 0; x < m; ++x){
            cin >> v1 >> v2 >> time;
            g[v1].push_back({time, v2});
            g[v2].push_back({time, v1});
        }
        int ans = _dijkstra(g, startCity, n, finishCity);
        g.clear();

        if (ans == INF){
            cout << "NONE" << endl;
        }else{
            cout << ans << endl;
        }
    }
    return 0;
}