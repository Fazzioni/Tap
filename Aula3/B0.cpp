#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll  m[5000+1][5000+1];
int xmax,ymax;

int   pinturas = 0;

void paint(int a,int b,ll color){
    if (a == 1){ // row
        for (int x = 0; x < xmax; x++)
            m[b][x] = color;
    } else  // column
        for (int y = 0; y < ymax; y++)
            m[y][b] = color;

    pinturas++;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int k;
    cin >> ymax >> xmax >> k;

    for (int y = y; y < ymax; y++)
        for (int x =0; x < xmax; x++)
            m[y][x] = 0;

    for (int i = 0; i < k; i++){
        int t, nm;
        ll color;
        cin>>t>>nm>>color;
        paint(t,nm-1,color);
    }

    for (int y = 0; y < ymax; y++){
        string s = "";
        for (int x=0; x < xmax; x++){
            cout<<s<< m[y][x];
            s =" ";
        }
        cout<<"\n";
    } // w


   cout<<"\n\n pinturas:"<<pinturas;
   
}