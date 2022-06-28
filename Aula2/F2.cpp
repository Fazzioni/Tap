#include <bits/stdc++.h>

using namespace std;

#define maxV 1000000+1

int p[maxV][3];
// p[] 
// p[]
// p[2] -> IF 

 
int max(int a, int b){if (a > b)  return a; else return b;}

int main(){
    ios::sync_with_stdio(false), cin.tie(0);

    for (int i = 0; i < maxV; i++){
        p[i][0] = -1;
        p[i][1] = -1;
        p[i][2] = false;
    }

    int N;cin>>N;

    for (int w = 0; w < N; w++){
        int a,b; cin>>a>>b;
        p[a][0] = b;
        p[b][1] = a;
    }

    vector<int> list[2];

    

    //cout<<"\n";


    // primeiro elemento
    int el = p[0][0];
    p[0][2] = true;
    while (el > 0){
        p[el][2] = true;
        list[0].push_back(el);
        //cout<<el<<" ";
        el=p[el][0];
        //if (el == 0) break;
    }
    
    //cout<<"\n LISTA[0]:"; for (int i = 0; i < list[0].size(); i++) cout<<" "<<list[0][i];
    //cout<<"\n P[0][1]: "<<p[0][1];
    // list[0] tem todos os elementos 
    
    //cout<<"\n";


    // Numeros que faltam
    //cout<<"\nNUMEROS QUE FALTAM PREENCHER A LISTA:";
    

    //int second = -1;
    int sec = -1;
    for (int i = 0; i < maxV; i++)
        if ((!p[i][2]) && (p[i][1] != -1)){
            sec = i;
            break;
            //cout<<"\np["<<i<<"] "<<p[i][1]<<" "<<p[p[i][1]][1];                
            //if (p[p[i][1]][1] == -1){second = i;break;}
        }
    if (sec == -1)
        sec = 0;

    

    //cout<<"\n comeca a segunda lista com: "<<sec<<"\n";
    // busca os elementos a esquerda de sec
    list[1].push_back(sec);
    el = p[sec][1];
    while (el > 0){
        list[1].insert(list[1].begin(),el);
        p[el][2] = true;
        //cout<<el<<" ";
        el=p[el][1];
        if (el == 0) break;
    }
     

    
    // busca os elementos a direita de sec
    p[sec][2] = true;
    el = p[sec][0];
    
    //if ((el != 0) || (!p[el][2]));
    while ((el > 0) && (!p[el][2])){
        list[1].push_back(el);
        //cout<<el<<" ";
        el=p[el][0];
        //sif (p[el][2])  break;
    }
    
 //   cout<<"LISTA[0]:"; for (int i = 0; i < list[0].size(); i++) cout<<" "<<list[0][i];
 //   cout<<"\nLISTA[1]:"; for (int i = 0; i < list[1].size(); i++) cout<<" "<<list[1][i]; cout<<"\n";
    
    string s = "";
    int length = max(list[0].size(), list[1].size());
    for (int i = 0; i < length; i++){

        for (int l = 1; l >= 0; l--)
            if (i < list[l].size())
            if (list[l][i] != 0){
                cout<<s<<list[l][i];
                s=" ";
            }

    }

    cout<<"\n";
}
/*
2
0 2
1 0


*/


/*

    cout<<"\nsecond:"<<p[second][1]<<"   0:"<<p[0][1]<<", "<<p[0][1]<<"\n";

    el = p[second][1];
    p[0][2] = true;
    while (el != -1){
        cout<<el<<" ";
        list[1].push_back(el);
        el=p[el][0];
        if (el == 0) break;
    }
    cout<<"\n";
    cout<<"result:\n";
    int m =  max(list[0].size(),list[1].size());

    string ss = "";
    for (int i = 0; i < m; i++){
        if (i < list[1].size()){
            cout<<ss<<list[1][i];
            ss = " ";
        }

        if (i < list[0].size()){
            cout<<ss<<list[0][i];
            ss =" ";
        }
    }
    cout<<"\n";



    cout<<"\n\n\n";
    
    for (int i = 0; i < list[1].size(); i++)
        cout<<" "<<list[1][i];
    cout<<"\n";
    for (int i = 0; i < list[0].size(); i++)
        cout<<" "<<list[0][i];

    */

/*
2
0 2
1 0

*/



/*
9
30 50
0 20
20 40
40 60
60 80
10 30
50 70
70 90
80 0


9 0 20 20 40 40 60 60 80 10 30 30 50 50 70 70 90 80 0
*/


/*
5
0 11
10 12
11 13
12 14
13 0


10 11 12 13 14
*/