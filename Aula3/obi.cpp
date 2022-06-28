#include <bits/stdc++.h>

using namespace std;

int main(){
    int d;
    cin>>d;

    int r = 3;

    if (d <= 800)
        r = 1;
    else if ( d <= 1400)
        r = 2;    

    cout<<r<<"\n";
    


}