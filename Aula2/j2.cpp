#include <bits/stdc++.h>

using namespace std;

string s;
bool impossible;

bool IsPalindrome(){
        bool difA = false;        
        int b,e;
        b = 0;// begin
        e = s.size()-1; // end
        
        //string view[2];  view[0] = ""; view[1] = "";bool impar = (s.size()%2 !=0);

        while (b < e){
            if ((s[b] != 'a') || (s[e] != 'a')) 
                difA = true;

            if (s[b] != s[e])
                    return false;
            //else{view[0] +=  s[b];view[1] +=  s[e];}
            b++;e--;
        }
        if ((b == e) && (s[b]!='a'))
        difA = true;

        //cout<<"\n----->"<<s<<"\n"<<view[0]<<"\n"<<view[1];    
        if (!difA)  {
            impossible = true;
            return false;            
        }
        return true;
}


int main (){
    
    int T; cin>>T;
    //int T = 1;
    string fs = "";

    while(T--){
        cin>>s;
        bool hp = false; // has palindrome
        string ex = ""; // not palindrome
        impossible = false;

        // tst
        int index = 0;
        s.insert(s.begin(),'a');

        while (ex.size() == 0){ 
                if ((index+1 >= s.size()+1) || (impossible))
                    break;
                

                if ((index == 0) || ((index > 0) && (s[index-1] != s[index]) ))
                    if (!IsPalindrome())
                        ex = s;

                s[index] = s[index+1];
                s[index+1] = 'a';
                index++;
        }    
        

        if ((s.size()!= 0) && (!impossible)){
            cout<<fs<<"YES";
            cout<<"\n"<<ex;
         }else 
            cout<<fs<<"NO";
        fs ="\n";
        //if (impossible) cout<<"\n"<<"Impossible!";
        //cout<<"\n r:";if (b) cout<<"true"; else cout<<"false;";
    }
    cout<<"\n";
}