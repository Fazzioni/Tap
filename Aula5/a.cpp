#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin >> t;
    long long a,b;
    while (t--){
        cin >> a >> b;

        int answer = 0;
        long long x = b - a;

        if ( a < b){

            if (x % 2 == 0) // x é par 
                answer = 2;    
            else // x é impar: A + b
                answer ++;

        } else
            if (a > b){

                if (x % 2 == 0) // x é par 
                    answer = 1;    
                else // x é impar: A + b
                    answer = 2;
            }

        cout<<answer<<'\n';

    }

}