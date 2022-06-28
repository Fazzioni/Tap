#include <bits/stdc++.h>

using namespace std;

int m[1001][1001][5];

int fi[1001]; // first 1, para verificar a visao da esquerda

int main(){
    int n,mx;
    cin>>n>>mx;

    bool InLine = false;
    for (int i = 0; i < n; i ++){
        fi[i] = -1;

        for (int j =0; j < mx; j++){ 
            cin>>m[i][j][0];

            m[i][j][1] = 0; // direita
            m[i][j][2] = 0; // cima
            m[i][j][3] = 0; // esquerda
            m[i][j][4] = 0; // cima
        
            if (m[i][j][0] == 1){ // aplica uma cor aos itens anteriores

                if (fi[i] != -1) // lado esquerdo
                    fi[i] = j;

                for (int k = j; k >= 0; k--)
                    if (m[i][k][1] == 0)
                        m[i][k][1] = 1;
                    else
                        break;
                for (int k = i; k >= 0; k--)
                    if (m[k][j][2] == 0)
                        m[k][j][2] = 1;
                    else
                        break;
            }   
        }   
    }   


    for (int i = 0; i < n; i ++){

        if (fi[i] != -1)
            for (int j = fi[i]; j < mx; j++)
                m[i][j][3] = 1;
    }



    int p = 0;
    for (int i = 0; i < n; i ++)
        for (int j =0; j < mx; j++)
            if (m[i][j][0] == 0){ 
                if (m[i][j][1] == 1) p++;
                //if (m[i][j][2] == 1) p++;
                //if (m[i][j][3] == 1)  p++;
            }

        
        
    

    cout<<p;
}