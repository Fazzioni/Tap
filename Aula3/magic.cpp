#include <bits/stdc++.h>


using namespace std;

int main(){
    static int N = 8;
    int m[N][N];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            m[i][j] = 0;

    for (int n = 0; n < 32; n++){
        // cout<<
    }

    int i,j;
    i=0, j=0;
    //for (int n = 1; n <= 32; n++){
    for (int n = 1; n <= 8; n++){
        m[i][j] = n;
        m[7-i][7-j] = 65-i;
        j--;
        i = (n/8)+
    }


    // print
    for (int k = 0; k < N; k++){
        cout<<"\n";
        for (int l = 0; l < N; l++)
            cout<<" "<<m[k][l];
    }cout<<"\n";
}