#include <bits/stdc++.h>

using namespace std;


int  m[5000+1][5000+1];

struct Tinput{
    int align, position;
    int color;
};

Tinput fila[100000+1]; // [0] = type, [1] = element, [2] = color
int aux_fila[2][100000+1];  // ultima pintura
int xmax,ymax;

 
void paint(Tinput* value){
    if (value->align == 0){ // row
        for (int x = 0; x < xmax; x++)
            m[value->position][x] = value->color;
    } else  // column
        for (int y = 0; y < ymax; y++)
            m[y][value->position] = value->color;
}




int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int k;
    cin >> ymax >> xmax >> k;
    
 

    for (int a = 0; a < k; a++){
        aux_fila[0][a] = -1;
        aux_fila[1][a] = -1;
    }


    for (int y = y; y < ymax; y++)
        for (int x =0; x < xmax; x++) 
            m[y][x] = 0;
            

    for (int i = 0; i < k; i++){
        cin>> fila[i].align >> fila[i].position >> fila[i].color;
        fila[i].align--;  
        fila[i].position--; // começa no zero
        aux_fila[ fila[i].align ][ fila[i].position ] = i;
        //paint(t,nm-1,color);
    }
    
    for (int i = 0; i < k; i++)
        if (aux_fila[ fila[i].align ][ fila[i].position ] == i) // faz a pintura
            paint(&fila[i]);

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