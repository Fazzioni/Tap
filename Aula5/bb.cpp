#include <bits/stdc++.h>

using namespace std;

//long long int nuns[200000+1];

int main(){
    int t; cin >> t;
    while( t--){
        int n; cin >> n;
        int inf[2] = {0,0};

        // operacoes = *2
        // operacoes = div 2    
        for (int i = 0; i < 2*n; i++){
            cin >> nuns[i];
            inf[ nuns[i] % 2]++;
        }
        

        cout<<inf[0]<<" "<<inf[1]<<"    "<<abs(inf[0]-inf[1])/2<<"\n";
    }
}