#include <iostream>
#include <queue>


using namespace std;
#define blocked '#'
#define caminho '.'

char m[500][500];

int y_max,x_max;

void print(){
    cout<<'\n';
    for (int y= 0; y < y_max+2; y++){ 
        for (int x =0; x < x_max+2; x++) 
            cout<<m[y][x]<<" "; 
        cout<<"\n"; 
        }
}

struct TNode{ int y,x, custo;};

queue<TNode> fila;
int max_custo;

vector<pair<int,int>> moves = {{1,1},{1,-1},{-1,-1},{-1,1},{1,0},{0,1},{-1,0},{0,-1}};
    
void solveNode(TNode node){
    if (m[node.y][node.x] == caminho){
        

        m[node.y][node.x] = blocked;

        if (node.custo > max_custo)
            max_custo = node.custo;

        for (auto move : moves){
            TNode nodemove;
            nodemove.y = node.y + move.first;
            nodemove.x = node.x + move.second;
            nodemove.custo = node.custo+1;
            fila.push( nodemove);
        }
    }

}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        max_custo = 0;
        cin>>y_max>>x_max;
        // deslocamento
        for (int x = 0; x <= x_max+1; x++){ m[0][x]=blocked; m[y_max+1][x]=blocked;}
        for (int y = 0; y <= y_max+1; y++){ m[y][0]=blocked; m[y][x_max+1]=blocked;}

        // load map
        for (int y = 1; y <= y_max; y++)
            for (int x = 1; x <= x_max; x++)
                cin>>m[y][x];

        TNode node;

        node.y = 1;
        node.x = 1;
        node.custo = 0;

        fila.push(node);
        while (!fila.empty()){
            TNode node = fila.front();
            fila.pop();
            solveNode(node);
        }
        cout<<max_custo<<'\n'; 
    }
}