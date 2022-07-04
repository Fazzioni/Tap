#include <bits/stdc++.h>

using namespace std;

int main(){
    long long int el;
    int t,n; cin >> t;

    while(t--){
        cin >> n;
        int inf[2] = {0,0};

        for (int i = 0; i < 2*n; i++)
            cin >> el, inf[ el % 2]++;
        long long int max;
        if (inf[0] > inf[1]){ // 
        // se tiver mais numeros pares pode ser um problema
            max = inf[0] - inf[1]; 
            
            // impares * 2
            // existem mais pares

            // quantos numeros pares preciso transformar? max / 2,
            // quais os melhores numeros pares para isso?

            // dividir um multiplo de 2
            // 8 => 2³
            // 10 = 2^5
            // 


            
            cout<<"impar: "<<inf[0]<<" "<<inf[1]<<"\n";


            max = max / 2;

        }else // tem mais numeros impares!
            max = (inf[1] - inf[0])/2;

        cout<<max<<"\n";
    }
}