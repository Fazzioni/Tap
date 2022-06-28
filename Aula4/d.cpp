#include <bits/stdc++.h>
#define deslocamento 255
using namespace std;
int m[102][102];

int x_max,y_max, K;
int Distance(int y,int x){ return abs(y_max - y) + abs(x_max - x);}
int answer;

class Tnode{ 
    public:
        int y, x, c, d, h;
        Tnode(int _y,int _x,int _cp){
            y = _y, x = _x, c = _cp+m[y][x];
            d = Distance(y,x);
            if (x == y) d = d / 2;
            h = c + d;
        };
        bool operator<(const Tnode &node)const{ return (h > node.h); };
        bool operator>(const Tnode &node)const{ return (h < node.h); };
        bool operator==(const Tnode &node)const{ return (h == node.h);};
};

Tnode a = Tnode(0,0,0);
 
priority_queue<Tnode> pk;

pair<int, int> moves[3] = {{1,1},{0,1},{1,0}};

void solve(Tnode node){
    
    for (auto move : moves){
        Tnode tmp = Tnode(node.y+move.first,node.x+move.second, node.c);

            if (m[tmp.y][tmp.x] != deslocamento)
                if (tmp.c <= K){ // custo menor ou igual do que max bebida
                    if (tmp.d == 0){ // distancia até o ultimo ponto
                        //cout<<"S: ("<<tmp.y<<"."<<tmp.x<<"): "<<tmp.c<<"\n";
                        if ((answer == -1) || (answer > tmp.c))
                            answer = tmp.c;          
                        //break;
                    }else{
                        pk.push(tmp);
                        //cout<<node.y<<"."<<node.x<<": "<<node.c<<"\n";
                        
                    }
                    //cout<<"("<<node.y<<","<<node.x<<",   "<<node.c<<") ==> ("<<tmp.y<<","<<tmp.x<<",   "<<tmp.c<<")\n";
                }

    }//

    //cout<<"\n";
}

int main(){ // busca A*
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
            for (int x = 1; x <= x_max; x++)
                cin>>m[y][x];
                
        answer = -1;
        pk.push( Tnode(1,1,0));    
        while (!pk.empty()){
            auto node = pk.top();
            pk.pop();
            solve(node);
        }   
        cout<<answer<<'\n';
    }
}