#include <bits/stdc++.h>

using namespace std;
#define blocked '#'
#define caminho '.'

char m[102][102];

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

pair<int,int> moves[8] = {{1,1},{1,-1},{-1,-1},{-1,1},{1,0},{0,1},{-1,0},{0,-1}};
    
void solveNode(TNode node){



        if (node.custo > max_custo)
            max_custo = node.custo;

        for (auto move : moves){
            if (m[node.y + move.first][node.x + move.second] == caminho){
                m[node.y + move.first][node.x + move.second] = blocked;

                fila.push({node.y + move.first,node.x + move.second,node.custo+1});
            
            }

        }
    

}

int max_size_fila = 0;

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
     
        fila.push({1,1,0});
        m[1][1] = blocked;
 
        while (!fila.empty()){
            max_size_fila = max(max_size_fila,(int) fila.size());

            TNode node = fila.front();
            fila.pop();
 
            solveNode(node);
        }
        cout<<max_custo<<'\n'; 

 
    }


}