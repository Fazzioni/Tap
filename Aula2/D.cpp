//#include <bits/stdc++.h>
#include <iostream>
#include <vector>


using namespace std;


vector<int> all_rugs;

bool TestK(int kk){
    int k = kk;
    for (int i = 0; i < all_rugs.size(); i++)
        if (all_rugs[i] < k)
            continue;
        else if (all_rugs[i] == k)
            k--;
        else //if (all_rugs[i] > k)
            return false;
           
        return true;
}

int ma(int a, int b){return ((a+b)/2);}

int solve(){
    int menor = 1;
    int maior = 10;
    // buscar a maior ordem de grandeza de K

    while (!TestK(maior))
        maior = maior*10;


    int depth = 0;

    while (1){
        int media = ma(menor,maior);
        //cout<<"\nmenor: "<<menor<<"   ma: "<<media<<"   maior:"<<maior<<"  :";


        if (TestK(media)){ //  K = media, passou, mas é muito grande?

            //cout<<"Valor "<<media<<" passou";
            if (maior - menor <= 1){
                //cout<<"\n\n result: "<<media<<"\n";
                return media;
            }
        
            maior = media;

        } else{ // test K é pequeno demais

             if (maior - menor == 1)
                menor = maior;
            else
                menor = media;
        }

        depth++;
        //if (depth == 10) break;
    }



    return 0;
}

int main(){
    int T;
    cin>>T;

    vector<int> sol;

    
    while(T--){
        int rungs;
        cin>>rungs;
        all_rugs.clear();
        int last_rugs = 0;
        while (rungs--){
            int tmp;
            cin>>tmp;
            tmp -= last_rugs;
            last_rugs +=tmp;

            all_rugs.push_back(tmp);
        }
        // for (int i = 0; i < all_rugs.size(); i++) cout<<"\n "<<all_rugs[i];
        sol.push_back( solve() );
    }

    
    for (int i = 0; i < sol.size(); i++)
        cout<<"Case "<<(i+1)<<": "<<sol[i]<<"\n";
    


}