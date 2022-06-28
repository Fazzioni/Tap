#include <bits/stdc++.h>

using namespace std;


struct Tinput{ int align,position,color; };

 

int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    int xmax,ymax,k;
    cin >> ymax >> xmax >> k;
 
    int  m[ymax][xmax];
 
    for (int y = 0; y < ymax; y++)
        for (int x =0; x < xmax; x++) 
            m[y][x] = 0;
            
    for (int i = 0; i < k; i++){
        Tinput a;
        cin>> a.align >> a.position >> a.color;
        a.position--; // começa no zero

        if (a.align == 1){ // row
            for (int x = 0; x < xmax; x++)
                m[a.position][x] = a.color;
        } else  // column
            for (int y = 0; y < ymax; y++)
                m[y][a.position] = a.color;
    }

    for (int y = 0; y < ymax; y++){
        string s = "";
        for (int x=0; x < xmax; x++){
            cout<<s<< m[y][x];
            s =" ";
        }
        cout<<"\n";
    } // w
 
}