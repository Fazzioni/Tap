#include <bits/stdc++.h>
using namespace std;

char s[200000+1];

int main(){

    int t,length,r; 
    cin >> t;
    while (t--){       
        cin >> length;
        cin>>s;
        r = length;
        
        
        int last_index[2] = {-1,-1};

        for (int i = 0; i < length; i++){

            if (s[i] == '1'){
            
                cout<<(i-last_index[1]-1)<<"\n";
                r += i-last_index[1]-1;
                last_index[1] = i;
            }  else {
                cout<<(i-last_index[0]-1)<<"\n";
                 r += i-last_index[0]-1;
                last_index[0] = i;
            }         

        }
        
     
        cout<<"\n\n";
        cout<<r<<"\n";
        
    }

}
 

/*
0
10
0110
10010110
0110100110010110
10010110011010010110100110010110
0110100110010110100101100110100110010110011010010110100110010110

0110
*/