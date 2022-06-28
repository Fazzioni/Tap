#include <bits/stdc++.h>

using namespace std;

string s; 

bool compare(int k){
    // compara se sequencia de k1 é menor que k2
    // k1 < k2
    // sequencia de k1:

    bool b = false;
    for (int i = k; i >= 0; i--){
        int k2 = i+2;
        if (!b){b = true; k2 = k+1;}
        
        //cout<<"\n"<<i;
        //cout<<" "<<k2;
        if (s[k2] < s[i])
            return true;
        else
        if (s[k2] == s[i])
            continue;
        else
            return false;
    }

    return false;
}

int main(){
     ios::sync_with_stdio(false), cin.tie(0);

    /*
    s = "dcaab";
    for (int i =0; i < s.size();i++)
        cout<<compare(i);
    return 0;
    */

    int N; cin>>N;
    while(N--){
        int l; cin>>l;
       cin>>s;
        
        int k = 0;
        for (int i = 1; i < l; i++)
            if (s[i-1] > s[i])
                k = i;
            else 
            if (s[i-1] == s[i]){ // i < 
                if (compare(k))
                    k = i;
                else
                    break;
            } else
                break;

        //cout<<"\nk="<<k<<"\n";
        for (int i = 0; i <= k; i++)
            cout<<s[i];

        for (int i = k; i >= 0; i--)
            cout<<s[i];
        cout<<"\n";   
    }

}


/*

1
4
dcaa


*/