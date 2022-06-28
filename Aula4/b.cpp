#include <bits/stdc++.h>

using namespace std;


int h[3];

int main(){
    int t;
    cin >> t;

    while (t--){
        int n; cin>>n;
        
        int i = n/3;
        h[0] = i+1;
        h[1] = i;
        h[2] = i-1;

        int s = n % 3;

        if (s > 0) s--, h[0]++;
        if (s > 0) s--, h[1]++;
        cout<<h[1]<<" "<<h[0]<<" "<<h[2]<<"\n";
    }

}