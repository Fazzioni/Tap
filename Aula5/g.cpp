#include <bits/stdc++.h>

using namespace std;

int els[1000000+10];

int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    
    int n;
    while( cin >> n, n){

        for (int i = 0; i < n; i ++)
            cin >> els[i];

        /*int start = 1;
        while (start <= n)
            start = start * 2;
        start = start / 2;
        int start_up = start / 2;

        int delta = start - start_up;
*/
        int start = (n-1)/2 +(n-1)%2;
        int soma = 0;
        for (int i = start; i < n; i++)
            soma += els[i];

            
        cout<<soma<<"\n";
        

    }


}