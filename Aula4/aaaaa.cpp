#include <iostream>
#include <queue>


using namespace std;
#define blocked '#'
#define caminho '.'

char m[500][500];

long long int y_max,x_max;

void print(){
    cout<<'\n';
    for (long long int y= 0; y < y_max+2; y++){ 
        for (long long int x =0; x < x_max+2; x++) 
            cout<<m[y][x]<<" "; 
        cout<<"\n"; 
        }
}

 

queue<vector<long long int>> fila;
long long int max_custo;

vector<pair<long long int,long long int>> moves = {{1,1},{1,-1},{-1,-1},{-1,1},{1,0},{0,1},{-1,0},{0,-1}};
    
void solveNode(vector<long long int> node){
    if (m[node[0]][node[1]] != blocked){
        

        m[node[0]][node[1]] = blocked;

        if (node[2] > max_custo)
            max_custo = node[2];

        for (auto move : moves){
            vector<long long int> nodemove;
            nodemove.push_back(  node[0] + move.first );
            nodemove.push_back(  node[1] + move.second );
            nodemove.push_back( node[2]+1 );
            fila.push( nodemove);
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    long long int t; cin >> t;
    
    while(t--){
        max_custo = 0;
        cin>>y_max>>x_max;
        // deslocamento
        for (long long int x = 0; x <= x_max+1; x++){ m[0][x]=blocked; m[y_max+1][x]=blocked;}
        for (long long int y = 0; y <= y_max+1; y++){ m[y][0]=blocked; m[y][x_max+1]=blocked;}

        // load map
        for (long long int y = 1; y <= y_max; y++)
            for (long long int x = 1; x <= x_max; x++)
                cin>>m[y][x];

        vector<long long int> node;

        node.push_back(1);
        node.push_back(1);
        node.push_back(0);// custo = 0;

        fila.push(node);
        while (!fila.empty()){
            auto node = fila.front();
            fila.pop();
            solveNode(node);
        }
        cout<<max_custo<<'\n'; 
    }
}