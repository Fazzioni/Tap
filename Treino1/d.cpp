#include <iostream>
#include <string>

using namespace std;

int main(){
    string a, p;

    cin>>a;
    cin>>p;

    int resultado = 0;
    for (int i = 0; i < a.size() - p.size()+1; i++){ 
        bool pass = false;
        
        for (int j =0; j < p.size(); j++)
            if (a[i+j] == p[j]){
                pass = true;
                break;
            }

        if (!pass)
            resultado++;
    }
    cout<<resultado;
}