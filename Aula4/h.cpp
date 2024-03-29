#include <bits/stdc++.h>

using namespace std;
#define blocked '#'
#define caminho '.'

char m[102][102];
int  r[102][102];

int y_max,x_max;

void print(){
    cout<<'\n';
    for (int y= 0; y < y_max+2; y++){ 
        for (int x =0; x < x_max+2; x++) 
            cout<<m[y][x]<<" "; 
        cout<<"\n"; 
        }
}
void printR(){
    cout<<'\n';
    for (int y= 1; y <= y_max; y++){ 
        for (int x =1; x <= x_max; x++)
            if (r[y][x] == -1)
                cout<<"  ";
            else
                cout<<r[y][x]<<" "; 
        
        cout<<"\n"; 
        }
}

struct TNode{ int y,x, custo;};

queue<TNode> fila;
int max_custo;

pair<int,int> moves[8] = {{1,1},{1,-1},{-1,-1},{-1,1},{1,0},{0,1},{-1,0},{0,-1}};
    
void solveNode(TNode node){
    if (m[node.y][node.x] == blocked) 
        return;

    m[node.y][node.x] = blocked;
    r[node.y][node.x] = node.custo;

    if (node.custo > max_custo)
        max_custo = node.custo;

    for (auto move : moves)
        fila.push({node.y + move.first,node.x + move.second, node.custo+1});
}

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        max_custo = 0;
        cin>>y_max>>x_max;
        // deslocamento
        for (int x = 0; x <= x_max+1; x++) m[0][x]=blocked, m[y_max+1][x]=blocked;
        for (int y = 0; y <= y_max+1; y++) m[y][0]=blocked, m[y][x_max+1]=blocked;
     
        // load map
        for (int y = 1; y <= y_max; y++)
            for (int x = 1; x <= x_max; x++){
                cin>>m[y][x];
                r[y][x] = -1;
            }
       
        fila.push({1,1,0});
        while (!fila.empty()){
            TNode node = fila.front();
            fila.pop();
            solveNode(node);
        }
        printR();
        
        cout<<max_custo<<'\n'; 
    }
}