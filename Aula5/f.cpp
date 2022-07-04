#include <bits/stdc++.h>

using namespace std;


int N;
vector<int> f[101];
int peso[101][101];
int visited[101];
int custo[2];



/*
void dfs(int index){
    if (visited[index] != 0)
        return;
    
    visited[index] = 1;


    for (int i =0; i < f[index].size(); i++)
        if (visited[f[index][i]] == 0 ){
            custo[0] += peso[index][i];
            custo[1] += peso[i][index];
            
            dfs(f[index][i]);
        }

}*/

int main(){
    cin >> N;

    for (int w = 0; w < N; w++){
        int a,b,c; cin >> a >> b >> c;
        peso[b][a] = 0;
        peso[a][b] = c;

        f[a].push_back(b);
        f[b].push_back(a);
    }

    //fs(1);
    //cout<<min(custo[0],custo[1])<<'\n';
    //cout<<custo[0]<<", "<<custo[1];



    for (int i = 1; i <= N; i++){
        cout<<"\n["<<i<<"] = "<<f[i][0]<<"("<<peso[f[i][0]][i]<<")    ,"<<f[i][1]<<"("<<peso[i][f[i][1]]<<")";
        custo[0] += peso[f[i][0]][i];
        custo[1] += peso[i][f[i][1]];
    }
    cout<<"\n";
    cout<<min(custo[0],custo[1])<<'\n';
    cout<<max(custo[0],custo[1])<<'\n';

}