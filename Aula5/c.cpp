#include <bits/stdc++.h>

using namespace std;

vector<int> els[100000+10];


int cbfs[100000+10]; // cor do bfs
//char cdfs[100000+10]; 
int dbfs[100000+10]; // distancia anterior de cada no

queue<int> fila;
int last_node = -1;

int m = 0;
/*
void dfs(pair<int,int> v){
    if (cdfs[v.first] == 1)
        return;

    if (m < v.second)
        m = v.second;

    cdfs[v.first] = 1;

    for (int a : els[v.first])
        dfs({a,v.second + 1});
}*/


void SolveNode(int x ){
    cout<<"Solve["<<x<<"]\n";

    cbfs[x]++; // "cor": qtd de vezes que entrou na fila

    if (els[x].size() -1 == cbfs[x]){  // se tiver so 1 conexao

        for (int i : els[x])
            if (els[i].size() -1 > cbfs[i]){
                fila.push(i);
                dbfs[i] = max(dbfs[i], dbfs[x]+1);
                cout<<"     push("<<i<<")\n";
            }
    }else cout<<"       reject: "<< x<<"  ("<<cbfs[x]<<"/"<<els[x].size()<<")\n";                

    last_node = x;
};

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        
        // load
        for (int i = 0; i < n-1; i ++){
            int a,b; cin >> a >> b;
            els[a].push_back(b);
            els[b].push_back(a);

            cbfs[i] = 0;
            dbfs[i] = 0;
//          cdfs[i] = 0;
        }


        // achar o centro - busca em largura
        for (int i = 0; i < n; i ++)
            if (els[i].size() == 1){ // coloca na fila se: conexao == 1
                fila.push(i);
                cbfs[i] = -1;
            }


        last_node = -1;
        while (!fila.empty()){
            int x = fila.front();
            fila.pop();
            SolveNode(x);
        } 
        
        cout<<"center node "<<last_node<<"\n";
        cout<<"distance:  "<<dbfs[last_node]<<"\n";

        //cout<<"\n";

        // busca em profundidade
        m = 0;
        //dfs({last,0}); cout<<m<<"\n";

        // limpar a lista
        for (int i = 0; i < n; i ++)
            els[i].clear();
    }
}