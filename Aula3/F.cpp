#include <bits/stdc++.h>

using namespace std;

int main(){
    int k,n; cin>>n>>k;
    cout<<setprecision(9);
    cout<<fixed;

    
    int x,y;
    cin>>x>>y;
    n--;
    double distance = 0;
    while (n--){
        int a,b;
        cin>>a>>b;
        
        distance += sqrt(pow(x-a,2) + pow(y-b,2));
        x = a;
        y = b;
    }
    cout<<(distance*k)/50.0<<"\n";


}   