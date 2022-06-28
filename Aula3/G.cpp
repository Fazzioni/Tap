#include <bits/stdc++.h>

using namespace std;

int min(int a,int b){ if (a <= b) return a; else return b;};
int min(int a,int b,int c){ return min(c,min(a,b)); };
int max(int a,int b){ if (a >= b) return a; else return b;};

int main (){
    // c = coders
    // m = mathematicians
    // x = without

    // q = queries 10⁴



    // supondo que  min(c,m) == c ( c =< m)
    // da para formar c times?
    //   m+x >= c     -> Sim:  
    // 
    //   m+x < c     -> Nao: 
    //               -> Deslocar 
    // da muito trabalho!


    // se eu pegar o min de m e c
    // jogar a diferença entre m e c para x
    // resposta = o minimo (c,m,x)
    // ---> Se x for o minimo: (nessa situacao m = c)
    // ------> numero de times = media aritmética?



    int q; cin>>q;
    while (q--){
        int c,m,x; cin>>c>>m>>x;

        int a,b;
        a = min(c,m);
        b = max(c,m);
        x += b - a;
        b = a;
    

        //if (min(a,b,x) == x){
        if (a > x){
            int r = (a - x)/3;
            a -= r;
            x += 2*r;

            if (x < a){
                a--;
                x+=2;
            }
        }

        cout<<min(a,x)<<"\n";            
        
        //cout<<"\n SOLVE: a:"<<a<<"   b:"<<b<<"     x:"<<x<<"\n";
    }
}

