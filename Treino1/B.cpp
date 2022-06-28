#include <iostream>
using namespace std;

int convert(char key){
    switch (tolower(key)){
        case 'r': return 0;
        case 'g': return 1;
        case 'b': return 2;
        default: return -1;
    }
}
 
int main(){
    int t = 0;
    cin>>t;
    string txt = "";

    for (int i = 0; i < t;i++){
         string s;
         cin>>s;
         string result = "YES";
         bool map[3] = {false};
         
         for (int j = 0; j < s.size(); j++)
            if (isupper(s[j])){ // 
                if (!map[convert(s[j])]){
                    result = "NO";
                    break;
                 }
            } else
                map[convert(s[j])] = true;   

        if (txt.size() != 0)
            txt +="\n";
        
        txt += result;
    }

    cout << txt <<endl;
}