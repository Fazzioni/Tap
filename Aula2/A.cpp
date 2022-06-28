#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    
    int office = 0;
    int crime = 0;
    while (N--){
        int e = 0;
        cin >> e;

        if (e != -1){ // police
            office += e;
        }else // = -1
            if (office > 0 )
                office --;
             else 
                crime++;

    }

    cout<<crime;

}