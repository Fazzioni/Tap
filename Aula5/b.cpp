#include <bits/stdc++.h>

using namespace std;



int main(){
    long long int el;
    int t,n; cin >> t;

    while(t--){
        cin >> n;
        long long int inf[2] = {0,0};

        priority_queue<int, vector<int>, greater<int>> pfila;
        //priority_queue<int> pfila;
    
        for (int i = 0; i < 2*n; i++){
            //el % 2 == 0 :. par
            //el % 1 == 1 :. impar
            cin >> el; 
            int index_par = el % 2;
            inf[ index_par ]++;

            
            if (index_par == 0){
                int divisoes = 0;

                while ( el % 2 == 0){
                    el = el / 2;
                    divisoes ++;
                }
                pfila.push(divisoes);
            }

        }
        

        long long int answer = 0;

        if (inf[0] > inf[1]){ // 
        // se tiver mais numeros pares pode ser um problema
            int len_div = (inf[0] - inf[1])/2; 

            // impares * 2
            // existem mais pares

            while (len_div > 0){
                auto node = pfila.top();
                pfila.pop();
                answer += node;
                len_div--;
            }
            
            // dividir um multiplo de 2
            // 8 => 2³
            // 10 = 2*5
            //cout<<"impar: "<<inf[0]<<" "<<inf[1]<<"\n";


        }else // tem mais numeros impares!
            answer = (inf[1] - inf[0])/2;

        cout<<answer<<"\n";
    }


}