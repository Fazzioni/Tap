#include <bits/stdc++.h>

using namespace std;


int main(){
    int N; cin>>N;
    while(N--){
        int l; cin>>l;
        string s; cin>>s;
        
        int k = 0;
        for (int i = 1; i < l; i++)
            if (s[i-1] > s[i])
                k = i;
            else            
                break;

        for (int i = 0; i <= k; i++)
            cout<<s[i];

        for (int i = k; i >= 0; i--)
            cout<<s[i];
        cout<<"\n";   
    }

}