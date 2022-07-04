#include <bits/stdc++.h>

using namespace std;
#define maxM 500000+1

char Mv[maxM];
vector<int> f[maxM];


int tmp_answer = 0;
int N;

void search(int el){
   // cout<<"\n Busca "<<el<<"   ";

    for (int i = 0; i < f[el].size(); i++){
        //cout<<"\n     "<<f[el][i];

        if (Mv[ f[el][i] ] ==  0){
            Mv[ f[el][i] ] = 1; // faz  a marcação
            tmp_answer++;
            search(f[el][i]);
        }
    }
}

int GetNext(){
    for (int i = 0; i <= N; i++)
        if (Mv[i] == 0)
            return i;

    return -1;
}

int main(){
    int t,M; cin >> t;
    
    while (t--){
        cin >> N >> M;
        //cout<<"     "<<t<<"   ";

        // limpa
        for (int i = 0; i <= N; i++) {
            Mv[i] = 0;
            f[i].clear();
        }
    
        // load
        for (int i = 0; i < M; i++){
            int a,b; cin >> a >> b;
            f[a].push_back(b);
            f[b].push_back(a);
        }  


        int answer = 0;
        //int visited = 0; 
        
        // solve
        int el = -1;
        while( el = GetNext(), el != -1){
            // comeca a busca por el
            tmp_answer = 1;

            //cout<<"\n "<<el;

            Mv[el] = 1;
            search(el);

            if (tmp_answer > answer)
                answer = tmp_answer;


            //cout<<"\n";for (int i = 0; i <= N; i ++)cout<<i<<": "<<(int) Mv[i]<<"   ";

        }  

        cout<<answer<<'\n';
    }

}