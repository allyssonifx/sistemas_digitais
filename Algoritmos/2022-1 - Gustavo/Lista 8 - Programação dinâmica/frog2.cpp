#include <bits/stdc++.h>
using namespace std;

class Frog{
    public:
        vector <int> pesos;
        vector <int> stones;
        int totalJumps;
        int size;

        Frog(int size, int jumps){
            this->pesos.resize(size);
            this->stones.resize(size);
            for(int i=0;i<size;i++){
                this->stones[i]=10001;
            }
            this->totalJumps=jumps;
            this->size=size;
        }

        int distance(int pos1, int pos2){
            if(pos2 < 0)
                return 1001;
            else
                return abs(this->stones[pos1] - this->stones[pos2]);
        }


        int peso(int pos){
            if(pos < 0)
                return 0;
            else
                return this->pesos[pos];

        }
        

        int minTravel(){
            for (int j = 1; j < this->stones.size();j++){
                //vector<int> list_dist;
                int minVal = INT_MAX;
                //cout << "Qual o menor trajeto para chegar na pedra " << j << endl;
                for (int i = 1; i < this->totalJumps+1; i++){
                    if (j - i >= 0){
                        int d, p, dist;
                        d = distance(j,j-i);
                        p = peso(j-i);
                        dist = d + p;
                        //list_dist.push_back(dist);
                        minVal = min(minVal, dist);
                        //cout << 4-i << ". " << j+i << " -> " << d << " + " << p << " == " << dist << endl;
                        }
                }
                //cout << "R = "<< minVal << endl;
                this->pesos[j] = minVal;
            }
            return this->pesos[size-1];

        }

};

int main(){
    int st, limit;
    cin >> st >> limit;

    Frog f(st, limit);

    int x;
    for(int i = 0; i <st;i++){
        cin >> x;
        f.stones[i] = x;
    }

    cout << f.minTravel() << endl;

}