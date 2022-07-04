#include <bits/stdc++.h>

using namespace std;

int xmax, ymax;

char m[500+10][500+10];
char cm[500+10][500+10];

queue<vector<int>> fila;
int answer = -1;


bool validMove(pair<int,int> move){ 
    return ((move.first >= 0) && (move.first < ymax) && 
            (move.second >= 0) && (move.second < xmax) && 
            (cm[move.first][move.second] == 0) // "color"
            );};
bool IsArrived(pair<int,int> move){ return ((move.first == ymax-1) && (move.second == xmax-1));};


void solve(vector<int> p){
    
    //cout<<"...:"<<p[0]<<", "<<p[1]<<"\n";

    cm[p[0]][p[1]] = 1;
    int v = m[p[0]][p[1]];
    if (v == 0)
        return;
    pair<int,int> moves[4] = {{p[0]+v,p[1]}, {p[0]-v,p[1]}, {p[0],p[1]+v}, {p[0],p[1]-v}};

    for (auto move : moves){
        //cout<<move.first<<','<<move.second<<'\n';
        if (validMove(move))
            if (IsArrived(move)){
                answer = p[2]+1;
                //cout<<"Found: "<<move.first<<", "<<move.second<<"     "<<p[2]+1<<"\n";
                while (!fila.empty()) 
                    fila.pop(); 
                return;

            }
            else
                fila.push({move.first, move.second,p[2]+1});
        
    }

}

int main(){
    cin >> ymax >> xmax;    
    // load
    for (int y = 0; y < ymax; y++)
        for (int x = 0; x < xmax; x++)
            cin>>m[y][x], m[y][x] -='0';
 
    // BFS
    fila.push( {0,0,0} );

    while (!fila.empty()){
        auto node = fila.front();
        fila.pop();
        solve(node);
    }

    cout<<answer<<"\n";


}