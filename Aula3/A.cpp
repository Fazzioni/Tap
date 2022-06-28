#include <bits/stdc++.h>

using namespace std;

char m[51][51];

void Swap(int y, int x){
    if ((y > 0) && (m[y-1][x] == '*') && (m[y][x] == '.')){ // swap{
        // verifica se a linha de cima é uma pedra
        m[y-1][x] = m[y][x];
        m[y][x] = '*';
        Swap(y-1,x);
    }
}

int main(){
    int t;  cin >> t;
    while(t--){
        int xmax,ymax; cin>>ymax>>xmax;

        for (int y = 0; y < ymax; y++)
            for (int x =0;  x < xmax; x++){
                cin>>m[y][x];
                Swap(y,x);
            }


   

        for (int i = 0; i < ymax; i++){
            for (int j =0; j < xmax; j++)
                cout<<m[i][j];
            cout<<"\n";
        }
    }
}