#include <bits/stdc++.h>

using namespace std;

vector<int> els[100000+10];


int cbfs[100000+10];
char cdfs[100000+10];

int m = 0;

void dfs(pair<int,int> v){
    if (cdfs[v.first] == 1)
        return;

    if (m < v.second)
        m = v.second;

    cdfs[v.first] = 1;

    for (int a : els[v.first])
        dfs({a,v.second + 1});
}


int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        // load
        for (int i = 0; i < n-1; i ++){
            cbfs[i] = 0;
            cdfs[i] = 0;

            int a,b; cin >> a >> b;
            els[a].push_back(b);
            els[b].push_back(a);
        }

        // achar o centro - busca em largura
        queue<int> fila;
        for (int i = 0; i < n; i ++){
            if (els[i].size() == 1){ // coloca na fila se: conexao == 1
                fila.push(i);
                cbfs[i]--;
                //cout<<"\ninsert: "<<i;
            }
        }

        int last = -1;

        while (!fila.empty()){
            int x = fila.front();
            fila.pop();
            
            cbfs[x]++;
            // solve node
                if (els[x].size() -1 == cbfs[x]){ 
                   
                    for (int i : els[x])
                        if (els[i].size() -1 > cbfs[i]){
                            fila.push(i);
                            //cout<<"    add fila    "<<i;
                    }

                }//else cout<<"  reject: "<< x<<"  ("<<cbfs[x]<<"/"<<els[x].size()<<")";                

            last = x;      
        } // while
        //cout<<"center node "<<last<<"\n";

        // busca em profundidade
        m = 0;
        dfs({last,0});
        cout<<m<<"\n";


        // limpar a lista
        for (int i = 0; i < n; i ++)
            els[i].clear();
    }
}