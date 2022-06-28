#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin>>T;

    

    while (T--){
        //cout<<"\nT:"<<T<<"\n";
        int N;   cin>> N; // students
        
        long long int shoes[N][3]; // 0 -> shoes size
                                   // 1 -> shoes index
                                   // 3 -> moved

        
        for (int o = 0; o < N; o++){
            cin>>shoes[o][0];
            shoes[o][1] = o+1;
            shoes[o][2] = false;
        }

        bool passed = true;
 
        
        for (int i = N-1; i > 0; i--){ 
            if (shoes[i-1][0] >= (shoes[i][0])){ // pode fazer a troca
                long long tmp = shoes[i-1][1];
                shoes[i-1][1] = shoes[i][1];
                shoes[i][1] = tmp;

                shoes[i][2] = true;
                shoes[i-1][2] = true;
            } else {

                    // o item anteior nao pode fazer a troca
                    if (!shoes[i][2]) {
                        passed = false;     
                        break;
                    }

            }
        }

        if (!shoes[0][2])
            passed = false;

        if (passed){
            string ss = "";
            for (int o = 0; o < N; o++){
                cout<<ss<<shoes[o][1];
                ss=" ";
            }
            
        } else 
            cout<<"-1";
            
        cout<<"\n";
        
        
        

        // começo da esquerda para direita
        // faço uma mudança para esquerda
        // se for possivel trocar com o anterior OK se não print -1
        
        // para passar tem que ter pelo menos 2 sapatos de cada número

    }


}