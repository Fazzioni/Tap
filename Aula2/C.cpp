#include <bits/stdc++.h>
#include <string>
using namespace std;


int main(){
    char i;
    string s = "";
    int last = -1;

    while (true){
        int a,v;
        i = getchar();
        switch(i){
            case '\0':
            case '\n':
                if (s.size() == 0){
                    cout<<"0";
                }else
                    cout<<s;
                return 0;

            default:
                v = int(i)-48;
                a = 9 - v;

                if ((a >= 0) && (a < v)) v = a;

       
                if ((s.size() == 0) && (v == 0)) 
                    s.push_back('9'); 
                else
                    s.push_back(v+48);
        }

    }

}