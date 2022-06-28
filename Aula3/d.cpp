#include <bits/stdc++.h>

using namespace std;
#define len 300+1

char letter[2]; // 0 = diagonal, 1 = fora da diagonal
char m[len][len];

void printNo(){   cout<<"NO\n"; }

int main(){
    int n;cin>>n;
     
    for (int y = 0; y < n; y++)
        for (int x = 0; x < n; x++)
            cin>> m[y][x];         

    letter[0] = m[0][0];
    letter[1] = m[0][1];
    
    if (letter[0] == letter[1]){
        printNo();
        return 0;
    }

    
    int xx = n;
    for (int y = 0; y < n; y++){
        xx--;
        for (int x = 0; x < n; x++)
            if (x == y){
                if (m[y][x] != letter[0]){
                    printNo();
                    return 0;
                }
            } else if (x == xx){
                if (m[y][x] != letter[0]){
                    printNo();
                    return 0;
                }

            } else {
                if (m[y][x] != letter[1]){
                    printNo();
                    return 0;
                }
            } 
    }

   cout<<"YES\n";
     /*
   
    int jx = n;
    for (int y = 0; y < n; y++){
        jx--;
        for (int x = 0; x < n; x++){
            if (x == y){
                m[y][x] = 'X';
            }else
                if (x == jx){
                    m[y][jx] = 'X';
                } else{
                    m[y][x] = '.';
                }
        }
    }
   */

    //cout<<"\n\n";for (int y = 0; y < n; y++){ for (int x = 0; x < n; x++) cout<<m[y][x]; cout<<"\n";}

}