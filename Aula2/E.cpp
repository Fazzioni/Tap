#include <bits/stdc++.h>

using namespace std;

int main(){

    int N,Q;
    int index_case = 1;
    string S = "";
    while (true){    
        cin>>N>>Q;
        if ((N == 0) && (Q == 0))
            break;

        bool found[10000+1];
        for (int i = 0; i <10000+1;i++)
            found[i] = false;

        //vector<int> el;
        //el.resize(N);

        int el[N];


        for (int i = 0; i < N; i++)
            el[i] = 0;
        
        

        //memset(found,false,N+1);
        //memset(el,0,N);

        for (int w = 0; w < N; w++){ // n
            int n; cin>>n;
            found[n] = true;
            el[w] = n; 
        }
        sort(el,el+N);

        cout<<S<<"CASE# "<<index_case<<":"; S = "\n";
        //for (int i = 0; i < el.size(); i++)cout<<"\n"<<el[i];
         

        for (int w = 0; w < Q; w++){ // q
            int q; cin>>q;

            bool exist = false;
 
            if (found[q]);
                for (int i = 0; i < N; i++)
                    if (el[i] == q){
                        cout<<"\n"<<q<<" found at "<<(i+1);
                        exist = true;
                        break;
                    }

            if (!exist)
                cout<<"\n"<<q<<" not found";
        }

        index_case++;
    }//
    cout<<"\n";
}