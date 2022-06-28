#include <bits/stdc++.h>

using namespace std;
#define deslocamento '#'
#define caminho '.'

char m[102][102];
int mc[102][102]; // matriz de custo

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

int solveNode(TNode node){
    if (m[node.y][node.x] != caminho)
        return 0;

    if (node.custo > max_custo)
        max_custo = node.custo;

    m[node.y][node.x] = '#';
    if (mc[node.y][node.x] == 0)
        mc[node.y][node.x] = node.custo;

    // buscar movimentos validos
    pair<int,int> moves[8] = {{1,1},{1,-1},{-1,-1},{1,0},{0,1},{-1,1},{-1,0},{0,-1}};
        for (auto move : moves)
            if (m[node.y + move.first][node.x + move.second] == caminho)
                if (mc[node.y + move.first][node.x + move.second] == 0)
                    fila.push({node.y + move.first,node.x + move.second,node.custo+1});

    return 0;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        max_custo = 0;
        cin>>y_max>>x_max;
        // deslocamento
        for (int x = 0; x <= x_max+1; x++) m[0][x]=deslocamento, m[y_max+1][x]=deslocamento;
        for (int y = 0; y <= y_max+1; y++) m[y][0]=deslocamento, m[y][x_max+1]=deslocamento;
        // matriz de custo
        for (int y = 1; y <= y_max; y++) for (int x = 1; x <= x_max; x++) mc[y][x]=0;

        for (int y = 1; y <= y_max; y++)
            for (int x = 1; x <= x_max; x++)
                cin>>m[y][x];
            

        fila.push({1,1,0});
        while (!fila.empty()){
            TNode node = fila.front();
            fila.pop();
            solveNode(node);
        }
        cout<<max_custo<<'\n'; 
        //print();
    }
    
     
}