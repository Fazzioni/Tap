#include <bits/stdc++.h>

using namespace std;


int els[1000000+1];
//int ks[1000000+1];

int n, k;
    

//int GetIndex(int a){// max = els[k]// min = 0 }

// void update(int a,int rem){}


int main(){
    cin >> n;
 
    for (int i = 0; i < n; i++)
        cin>>els[i];
        //ks[i] = els[n];
    cin>>k;

    int pe = k-1;
    int ps = 0;

    string s="";
    while (pe < n){
        int max = 0;
        for (int i = ps; i <= pe; i++){
            if (els[i] > max)
                max = els[i];
            //cout<<" "<<i;
        }
        //cout<<"\n";
        ps++;
        pe++;
        cout<<s<<max;
        s=" ";
    }
    cout<<"\n";

    // sort(ks, ks+n);
    //cout<<"\n"; for (int i = 0; i < n; i++) cout<<" "<<ks[i];
    
}