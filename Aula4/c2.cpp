#include <bits/stdc++.h>

using namespace std;

int m[1001][1001];
// guardar os primeiros e os ultimos elementos de cada linha e de cada coluna
int mx[1001][2]; // quarda as linhas
int my[1001][2]; // quarda as colunas



int main(){
    int yy,xx;
    cin>>yy>>xx;

    for (int x = 0; x < xx; x++)
        my[x][0] = 1001, my[x][1] = -1;
    
    

    for (int y = 0; y < yy; y ++){
        mx[y][0] = 1001, mx[y][1] = -1;

        for (int x =0; x < xx; x++){ 
            cin>>m[y][x];

            if(m[y][x] == 1){
                // primeiro elemento
                if (mx[y][0] == 1001 )  mx[y][0] = x; 
                // ultimo elemento
                mx[y][1] = x; 


                // colunas
                if (my[x][0] == 1001) my[x][0] = y;
                my[x][1] = y;
            }
        }   
    }   


    int p = 0;

    for (int y = 0; y < yy; y ++){
        //cout<<"\n mx:"<<mx[y][0]<<","<<mx[y][1];
        for (int x =0; x < xx; x++){      
            if (m[y][x] == 0){

                //direita
                if (mx[y][0] < x) p++;
            
                // esquerda
                if (mx[y][1] > x) p++;
                
                // baixo
                if (my[x][0] < y) p++;

                //cima
                if (my[x][1] > y) p++;
                
            } 

        }
    }
    
    //cout<<"\n";
    cout<<p<<"\n";
}