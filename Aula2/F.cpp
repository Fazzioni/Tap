#include <bits/stdc++.h>

using namespace std;

// eu preciso reduzir o vector em 2 elementos
vector< vector<int> > els;

bool InsertBack( vector<int> values){
    for (int i = 0; i < els.size(); i ++)
        if (els[i].size() == 0)
            return false;
        else
        if (els[i].back() == values.front() ){
            for (int j = 1; j < values.size(); j++)
                els[i].push_back(values[j]);
            return true;
        }
    return false;
}

bool InsertFront(vector<int> values){
    for (int i = 0; i < els.size(); i ++)
        if (els[i].size() == 0)
            return false;
        else
        if (els[i].front() == values.back()){
            for (int j = values.size()-2; j >= 0 ; j--)
                els[i].insert(els[i].begin(),values[j]);
            return true;
        }
    
    return false;
}


int main(){
    ios::sync_with_stdio(false), cin.tie(0);

    int N;

    // -1 = start
    // -2 = end
    //  0 = free

    // -1 x2 __ x4 __ x6 
    // x1 __ x3 __ x5 -2


    static int max_bool = 1000001;
    bool Add[max_bool];
    memset(Add,false,max_bool);

    /*
    for (int i = 0; i < 1000001; i++)
        Add[i] = false;
    */

    
    cin>>N;
    
    
    for (int i = 0; i < N; i++){
        int a,b; cin>>a>>b;

        if (a == 0) a = -1;
        if (b == 0) b = -2;
        vector<int> newItem = {a,b};

        if ((Add[a]) && (a!= -1)){
            InsertBack( newItem);
        } else if ((Add[b]) && (b!= -2)) {
            InsertFront(newItem);
        } else {
            els.push_back(newItem);

            //for (int i = 0; i < newItem.size(); i++)cout<<newItem[i]<<" ";
            Add[a] = true;
            Add[b] = true;
        }

    }   


    
    while (els.size() > 2){
        for (int i = els.size() -1;  i >= 0; i --){
            if ((els[i].front() != -1) || (els[i].back() != -2)){
                
                if ((InsertFront(els[i]) || (InsertBack(els[i])))){
                    els.erase(els.begin()+i);
                    break;
                }
            }
        }
    }


    int v = 0;
    if (els[0].front() != -1)
        v = !v;
    int max = els[0].size();
    if (els[1].size() > els[0].size())
        max = els[1].size();


    string s = "";

    for (int i = 0; i < max; i++){
        if ( els[v].size() > i)
            if (els[v][i] >= 0){
                cout<<s<<els[v][i];
                s=" ";
            }

        v = !v;
        if (els[v].size() > i)
            if (els[v][i] >= 0){
                cout<<s<<els[v][i];
                s=" ";
            }
        v = !v;
        
    }
    
    cout<<"\n";
}