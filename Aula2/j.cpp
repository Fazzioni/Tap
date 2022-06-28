#include <bits/stdc++.h>

using namespace std;

string s;

bool IsPalindrome(bool InsertA){
    bool inserted = false;
    bool difA = false;

        int b,e;
        b = 0;// begin
        e = s.size()-1; // end
        
        //string view[2];  view[0] = ""; view[1] = "";bool impar = (s.size()%2 !=0);

        while (b < e){
            
            if ((s[b] != 'a') || (s[e] != 'a'))
                difA = true;

            if (s[b] != s[e]){
                if ((!InsertA) || ((InsertA) && (inserted)))
                    return false;

                inserted = true;
                if (s[b] == 'a'){
                    //view[0]+='a';view[1]+='a';
                    e--;           
                    inserted = true;         
                } else if (s[e] == 'a'){
                    //view[0]+='a';view[1]+='a';
                    b--;            
                    inserted = true;        
                } else
                return false;
            } 
            //else{view[0] +=  s[b];view[1] +=  s[e];}

            b++;e--;
        }
        if ((b == e) && (s[b]!='a'))
            difA = true;

        //cout<<"\n----->"<<s<<"\n"<<view[0]<<"\n"<<view[1];    

        //if (!impar)cout<<"\npar";elsecout<<"\nimpar";

        if ((s.size()==0) || ((!difA)&&(InsertA)))
            return false;
        
        return true;
}

int main (){
    int T; cin>>T;

    string fs = "";

    while(T--){
        
        cin>>s;

        bool b = IsPalindrome(true);
        if (b){

            int index = 0;
            s.insert(s.begin(),'a');
            while (IsPalindrome(false)){

                    if (index+1 >= s.size()-1){
                        b = false;
                        break;
                    }

                    s[index] = s[index+1];
                    s[index+1] = 'a';
                    index++;
            }

        };

        if (b){
            cout<<fs<<"YES";
            cout<<"\n"<<s;
         }else 
            cout<<fs<<"NO";
        fs ="\n";

        

        //cout<<"\n r:";if (b) cout<<"true"; else cout<<"false;";

        



            //int midle = s.size() / 2;
            //for (int i = 0; i < midle;i++) cout<<s[i];
            //cout<<"\n";
            //for (int i = s.size()-1; i >= midle; i--) cout<<s[i];
            //cout<<"\n\n";





    }

    cout<<"\n";

}