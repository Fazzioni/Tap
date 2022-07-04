#include <bits/stdc++.h>

using namespace std;
char g[5000+10][5000+10];
vector<int> p[5000+10][2];

// p[i][0] = elemeto i gosta
// p[i][1] = elemntos que gostam de i

int n;
int main(){
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++){
        int a; cin>>a;
        // [0] = de quem p[i] gosta
        p[i][0].push_back(a);
        // [1] = quem gosta de p[i]
        p[a][1].push_back(i);
        g[i][a] = 1; 
    }

    // vamos para cada elemento achar um triangulo
    for (int i = 1; i <= n;i++)
        for( auto x : p[i][0])
           for( auto a : p[i][1]){
              //cout<<"\n"<<x<<" < "<<i<<" < "<<a<<":. "<<a<<" < "<<x<<"?";
              if (g[x][a] == 1){
                
              cout<<"YES\n";
              return 0;
              }
            }
            
    cout<<"NO\n";
}