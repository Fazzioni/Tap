#include <bits/stdc++.h>

using namespace std;


int  r[10001];

int GetOrdem(int a,int n){
    for (int i = 0; i < n; i++)
        a = a*10;
    
    return a;
}

int main(){
    
    int t;
    cin>>t;
 
    while (t--){
        string s;
        cin >> s;

        int op = 0;
 
        for (int i = s.size()-1; i >=0 ; i--)
            if (s[i] != '0')
                r[op] = GetOrdem( s[i]-'0',(s.size() - i-1)),op++;
                
        cout<<op<<'\n';
        s = "";
        for (int i = 0; i < op; i++)
            cout<<s<<r[i],s = " ";
        cout<<"\n";
    }
}