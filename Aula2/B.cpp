#include <iostream>

using namespace std;

int main(){
    int N;
    long long int ice;

    cin>>N>>ice;

      
    int without = 0;

    
    while (N--){
        char a[2]; int b;
        cin>>a>>b;

        if (a[0] == '+'){
            ice += b;
        } else {

            if (b > ice){

                without++;
            } else{
                ice -=b;
            }

    

        }
 
    }
 
    cout<<ice<<" "<<without<<endl;
}