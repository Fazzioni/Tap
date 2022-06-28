#include <iostream>
#include <vector>

using namespace std;
 

int main(){
    int N; // switchs [1..N+1]
    int M; // bulbs

    // first line
    cin>>N>>M;
    int shine = 0;

    bool Bulbs[M+1] = {false};
    vector<int> lines[N];

    // second line
    int L; cin >> L;
    for (int i = 0; i < L; i++){
        int key;
        cin >> key;
        Bulbs[key] = true;
        shine++;
    }


    for (int i = 0; i < N; i++){
        int max; cin >> max;
        for (int j = 0; j < max; j++){
            int tmp;  cin>>tmp;
            lines[i].push_back(tmp);
        }
    }
 
    int loop = 0;
    int index = 0;
    int switchs = 0;
    while (shine != 0){
        for (int i = 0; i < lines[index].size(); i++){
            if (Bulbs[ lines[index][i] ]) // se esta acesa
                shine--;
            else
                shine++;
            Bulbs[lines[index][i]] = !Bulbs[(lines[index][i])];
        }

        switchs++;
        index++;
        if (index >= N){
            index = 0;
            loop++;
        }

        if (loop >= 2)  break;
    }


    if (shine == 0)
        cout<<switchs<<endl;
    else
        cout<<"-1"<<endl;
    
}

/*

    getchar();
    for (int i = 0; i < N; i++){  // read all switchs
        char key;
        string number = "";
        while (key = getchar()){
            bool end_line = false;
            switch(key){
                case '\0':
                case '\n':
                        lines[i].push_back(stoi(number));
                        end_line = true;
                        break;
                case ' ':
                    lines[i].push_back(stoi(number));
                    number = "";
                    break;
                default:
                    number += key;
                    break;
            }
            if (end_line) break;
        }
    }


*/