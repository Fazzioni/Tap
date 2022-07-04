#include <bits/stdc++.h>
using namespace std;

char s[200000+1];

int main(){

    int t,length,r; cin >> t;
    while (t--){       
        cin >> length;
        cin>>s;
        r = length;
        
        
        for (int i = 0; i < length-1; i++){
            if (s[i] != s[i+1])
                r++;

        }

            //cout<<s[i]<<" ";
        cout<<r<<"\n";
        
    }

}

// se tiver 3 caracteres iguais ou mais seguidos, é um divisor de substrings


0
10
0110
10010110
0110100110010110
10010110011010010110100110010110
0110100110010110100101100110100110010110011010010110100110010110

0110