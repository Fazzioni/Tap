#include <iostream>
#include <string>

using namespace std;

int main(){
    int T;
    cin>>T;

    string result = "";
    for (int i = 0; i < T; i++){
        bool tmp_result = false;
        string alphabetical; cin>>alphabetical;
        char key; cin >> key;

        for (int j = 0; j < alphabetical.size(); j++)
            if ((alphabetical[j] == key) && ( j%2 == 0)){
                tmp_result = true;
                break;
                }
        
        if (result.size() != 0)
            result +='\n';

        if (tmp_result)
            result +="YES";
         else 
            result +="NO";
        
                
    }

    cout<<result<<endl;

}