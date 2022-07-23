#include <bits/stdc++.h>

#define clend  255;

using namespace std;

char board[8][8];
pair<int, int> fim;


void ClearBoard(){ for (int y = 0; y < 8; y++) for (int x = 0; x < 8; x++) board[y][x] = 0;}
bool ValidMove(pair<int,int> move){ return (move.first >= 0) && (move.first < 8) && (move.second >= 0 ) &&(move.second < 8);};
bool FinishMove(pair<int,int> move){ return ((fim.first == move.first) && (fim.second == move.second));};


queue<vector<int>> fila;


vector<pair<int,int>> moves = {{-2,-1}, {-2,1},   {-1,-2}, {-1,2},   {1, -2}, {1,2},   {2, -1}, {2,1}};


int answer;

void bfs(vector<int> node){ 
    
    if ( board[node[0]][node[1]]  == 1)
        return;

    if (FinishMove({node[0],node[1]})){
        //cout<< node[2]<<'\n';
        answer = node[2];
                        
                while (!fila.empty()) 
                    fila.pop();
                return;
    } 

    board[node[0]][node[1]]  = 1;

    for (auto move : moves){
        pair<int, int> new_move = {move.first + node[0], move.second + node[1]} ;
        if (ValidMove(new_move))
                fila.push( {new_move.first, new_move.second, node[2]+1} );
    }

}


int main(){
    string a,b;

     while(cin>>a){
        cin>>b;
        while (!fila.empty()) 
            fila.pop();
        ClearBoard();    

        vector<int> inicio = { (int)a[1]-'1', (int)a[0]-'a', 0}; // {line, collum, deapth)
        fim   = { (int)b[1]-'1',(int)b[0]-'a'};

 

        answer = 0;
        fila.push(inicio);
        while (!fila.empty()){
            auto node = fila.front();
            fila.pop();
            bfs(node);
        }
        //cout<<answer<<"\n";
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<answer<<" knight moves.\n";
        
    } 

}