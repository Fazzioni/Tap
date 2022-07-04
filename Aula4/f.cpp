#include <bits/stdc++.h>

using namespace std;

char s[200000 + 1];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >>T;
    int n,answer, a,b;
    while (T--){
        cin>>n;  
        answer = n; 
        cin>>s;
        
        char last_element = 0;
        for (a = 1; a < n-1; a++){
            b = a;
            // two points - move ponteiro b

        }
            

    }
}

/*
01 = 3 (0,1,01)
100 = 4 (1,0,0,10)
1001 = 8 (1,0,0,1, 10, 01, 001, 1001)

// fazer todas as combinacoes de 2 caracteres
// fazer as combinacoes de 2 com 2
// apenas com as sequencias 010 ou 101 que podem ter 2 caminhos diferentes
// como fazer um algoritmo para suportar?


//Se tiver Sn = Sn+1, deveria parar? sim pq a resposta do anterior é igual

 01011 =>  (1 -> 0 -> 1)
101011 => (0 -> 1 ->)

e se for de 2 em 2?

01 10 01 10 01 01 <- movimento igual ao anterior
 1  0  1  0  1  1 
   0     0     

0110 -> 1,0,0(110) -> 0

*/