#include <bits/stdc++.h>
#define deslocamento 255
using namespace std;
int m[102][102];
set<int> ms[102][102];

int x_max,y_max, K;
int answer;

struct Tnode{  int y, x, c; };
 
queue<Tnode> pk;

pair<int, int> moves[3] = {{1,1},{0,1},{1,0}};

void solve(Tnode node){
    if (node.c > K)
        return;

    if ((node.x == x_max) && (node.y == y_max)) // distancia até o ultimo ponto                        
        if (node.c >  answer)
            answer = node.c;         

    for (auto move : moves){
        int ny = node.y+move.first;
        int nx = node.x+move.second;

        if (m[ny][nx] != deslocamento){
            int custo = node.c + m[ny][nx];
            if (ms[ny][nx].find(custo) == ms[ny][nx].end()){
                pk.push({ny,nx,custo});    
                ms[ny][nx].insert(custo);
            }
        }
    }
}

int main(){  
    ios::sync_with_stdio(false); cin.tie(0);
    int T ;

    cin>>T;
    while(T--){
        cin>>y_max>>x_max>>K;
        
        // deslocamento
        for (int y = 0; y <= y_max+1; y++) m[y][0]=deslocamento, m[y][x_max+1]=deslocamento;
        for (int x = 0; x <= x_max+1; x++) m[0][x]=deslocamento, m[y_max+1][x]=deslocamento;

        //map
        for (int y = 1; y <= y_max; y++)
            for (int x = 1; x <= x_max; x++){
                cin>>m[y][x];
                ms[y][x].clear();
            }
                
        answer = -1;
        pk.push({1,1,m[1][1]});    
        while (!pk.empty()){
            auto node = pk.front();
            pk.pop();
            solve(node);
        }   

        cout<<answer<<'\n';       
    }
}