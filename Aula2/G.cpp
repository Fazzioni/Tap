#include <bits/stdc++.h>

using namespace std;


string s;

int GetSum(){
    int r = 0;
    for (int i = 0; i < s.size()-1; i++){
        int t = 0;
        if (s[i] == '1') 
            t = 10;
        if (s[i+1] == '1')
            t++;
        r += t;
    }
    return r;
}

struct TLast{
   int position = 0;
   int custo =0;
   int count =0;
};

int main(){
    int T;
    cin>>T;
    while (T--){
        int n; // length string
        long long k; // operacoes maximas
        cin>>n>>k;
        cin>>s;

        int custo = 0;
        //int last = 

        //TLast f1;


        // pegar o maximo e o minimo

        int max = -1;
        int min = -1;

        bool swap = false;

        for (int i = 0; i < s.size(); i++)
            if (s[i] == '1' ){
                if (i > max)
                    max = i;

                if (min == -1)
                    min = i;
            }
        
            

            if (max != -1){
                int cd = s.size()-1 - max; // custo para descolar 1 para diretita
                if (cd <= k){
                    k -= cd;
                    s[max] = s[s.size()-1];
                    s[s.size()-1] = '1';
                    swap = true;
                }
            }
            // se max == min

            if (min > 0)
                if ((!swap) || (min != max))
                if (min <= k){
                    s[min] = s[0];
                    s[0] = '1';
                }
            
            //cout<<"\n"<<s;
            cout<<GetSum()<<"\n";



           // cout<<"\nmin: "<<ce<<"    max:"<<cd;
    



        /*

        for (int i = s.size()-1; i >= 0; i--)
            if (s[i] == '1'){
                int n = last - i;
                
                custo += n;
                last = last-1;

                f1.count++;
                f1.position = i;
                f1.custo = n;
                //cout<<"\ncusto:"<<n<<"  move to "<<i<<"    next position:"<<last;
            }

       


        cout<<"\nCusto para empurrar todas a direita posição: "<<custo;

        // qual o custo para empurrar um elemento para a esquerda
        if (f1.count > 1){ // tem mais de 1 elemento
            // last = ultima posição
            custo -= f1.custo; // diminui o ultimo custo
            // calcula o custo para a primeira posição
            custo += f1.position;
        }

        cout<<"\nCusto para esquerda: "<<custo;
         */

        // minha soma so vai mudar
        // empurra 1 valor para a extrema esquerda
        // empurra o prox para extrema direita
        // 




        /*
        int v = GetSum();
            while (k > 0){  // 
        }
        */



        // como simplificar 101 -> 011 dado k max!
        // -> Uniao entre mínim local e minimo global

        // quantas operações preciso para calcular o minimo global?
        // ==> nem sempre minimo global é possivel
        // -----> Vamos supor que seja possivel
        // ----------> cada elemento 1 precisa vir antes de do ultimo 1 deslocado a direita
        // ----------> distancia de i até o ultimo 1: para cada 1 diminuo a distancia do swap
        // ----------> se alinhar da esquerda para direita => complexidade 10^5

        // ok
        // -----> Quando não é possivel 
        // -------> tiver elemento iguai

        /* => Minimo local? 
            ==> como eu sei o melhor valor para fazer o swap?
            o que eu posso fazer com k - minimo global?
            => mix entre jogar para a direita e unir 1010 -> 0110-
        
        */
        
        



    }
}

/*

1
4 1
1111

*/