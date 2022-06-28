#include <bits/stdc++.h>

using namespace std;

#define black '#'
#define white '.'
#define pinted '1' // item ja colocado na fila
#define deslocamento 'x' //matriz de deslocamento

char m[1003][1003];

int h,w; // heigth, width

void paint(){
    cout<<'\n';
    for (int y= 0; y < h+2; y++){ 
        for (int x =0; x < w+2; x++) 
            cout<<m[y][x]<<" "; 
        cout<<"\n"; 
        }
}

struct Tpos{int y =0; int x = 0; int ordem = 0;};
queue<Tpos> fila;
int max_ordem = 0;

void validaFila(Tpos a){
        if (m[a.y][a.x] == white){
            if (a.ordem > max_ordem) 
                max_ordem = a.ordem;
            m[a.y][a.x] = pinted;

            fila.push(a);
            //cout<<"\n"<<a.y<<"."<<a.x;
        }

}
void insert_fila(Tpos a){
    //cout<<"\n NEW FILA: "<<a.y<<"."<<a.x;
    pair<int,int> moves[4] = {{0,-1}, {0,1}, {1,0}, {-1,0} };
    for (auto i:moves)
        validaFila({i.first+a.y,i.second+a.x, a.ordem+1});
}



int main(){
    cin >> h >> w;

    // preenche a matriz de deslocamento
    for (int i = 0; i <= w+1; i++) m[0][i]=deslocamento, m[h+1][i]=deslocamento;
    for (int y = 0; y <= h+1; y++) m[y][0]=deslocamento, m[y][w+1]=deslocamento;

    
    // carrega o mapa
    for (int y= 1; y <= h; y++)
        for (int x =1; x <= w; x++){
            cin>>m[y][x]; 
            if (m[y][x] == black)
                fila.push({y,x,0}), m[y][x] = pinted;
        }
 
    while (!fila.empty()){
        Tpos x = fila.front();
        fila.pop();
        insert_fila(x);
        //cout<<max_ordem;paint();
    }

    cout<<max_ordem<<'\n';
}