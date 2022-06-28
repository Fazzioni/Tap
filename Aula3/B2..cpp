#include <bits/stdc++.h>

using namespace std;


struct Tinput{ int align,position,color; };



int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int xmax,ymax,k;
    cin >> ymax >> xmax >> k;
 

    int  m[ymax][xmax]; // 200mb    
    Tinput fila[k]; 
    int aux_fila[2][k];  // armazena a ultima pintura

    for (int a = 0; a < k; a++){
        aux_fila[0][a] = -1;
        aux_fila[1][a] = -1;
    }


    for (int y = 0; y < ymax; y++)
        for (int x =0; x < xmax; x++) 
            m[y][x] = 0;
            

    for (int i = 0; i < k; i++){
        cin>> fila[i].align >> fila[i].position >> fila[i].color;
        fila[i].align--;
        fila[i].position--; // começa no zero

        aux_fila[ fila[i].align ][ fila[i].position ] = i;
    }
    

    for (int i = 0; i < k; i++)
        if (aux_fila[ fila[i].align ][ fila[i].position ] == i){ // faz a pintura
            if (fila[i].align == 0){ // row
                for (int x = 0; x < xmax; x++)
                    m[fila[i].position][x] = fila[i].color;
            } else  // column
                for (int y = 0; y < ymax; y++)
                    m[y][fila[i].position] = fila[i].color;
        } else {
            cout<<"ignore("<<fila[i].align<<","<<fila[i].position<<","<<fila[i].color<<")\n";
        }

    // k = 10⁵
    // criar uma fila para ignorar linhas iguais

    for (int y = 0; y < ymax; y++){
        string s = "";
        for (int x=0; x < xmax; x++){
            cout<<s<< m[y][x];
            s =" ";
        }
        cout<<"\n";
    } // w
 
}