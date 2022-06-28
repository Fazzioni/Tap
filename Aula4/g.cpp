#include <bits/stdc++.h>

using namespace std;

#define deslocamento 255
char m[52][52][2];

int y_max,x_max;

bool GetSize(){ cin>>y_max>>x_max; return ((x_max != 0) && (x_max!=0));}

struct Tnode{int y,x, cust;};

int max_cust;
stack<Tnode> pilha;
pair<int,int> moves[8] = {{1,0},{-1,0},{0,1},{0,-1},  {1,1},{1,-1},{-1,1},{-1,-1}};


void solve(Tnode node){
    if (node.cust > max_cust) max_cust = node.cust;
    for (auto move : moves)
            if (m[move.first + node.y][move.second + node.x][1] == 0)
                if (m[move.first + node.y][move.second + node.x][0] -m[node.y][node.x][0]==1){
                m[move.first + node.y][move.second + node.x][1]=1;
                pilha.push({move.first + node.y,move.second + node.x, node.cust+1}); // dava para fzer pela diferença entre letras
                //cout<<""<<m[node.y][node.x][0]<<"  "<<node.y<<" . "<<node.x<<"\n";
        }
}

/*
void print(){
    cout<<"\n";
    for(int y = 1; y <= y_max; y++){
        for (int x = 1; x <= x_max; x++){
            cout<<m[y][x][0]<<" ";
        }
    cout<<"\n";
    }
}*/

int main(){
    int indice = 0;
    while (GetSize()){
        indice++;
        max_cust = 0;
        // matriz de deslocamento
        for (int x = 0; x <= x_max+1; x++) m[0][x][0]=deslocamento, m[y_max+1][x][0]=deslocamento;
        for (int y = 0; y <= y_max+1; y++) m[y][0][0]=deslocamento, m[y][x_max+1][0]=deslocamento;
        // load map
        for(int y = 1; y <= y_max; y++)
            for (int x = 1; x <= x_max; x++){
                cin >> m[y][x][0];
                if (m[y][x][0] == 'A'){
                    m[y][x][1] = 1;
                    pilha.push({y,x,1});
                } else 
                    m[y][x][1] = 0;
            }
        //print();

        // solve stack
        while (!pilha.empty()){
            Tnode node = pilha.top();
            pilha.pop();
            solve(node);
        }
        cout<<"Case "<<indice<<": "<<max_cust<<"\n";
    }
}

// nos podemos marcar se algume ja passou pela cell
