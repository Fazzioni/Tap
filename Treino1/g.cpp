#include<iostream>

using namespace std;

int main(){

    int N, won = 0;

    cin>>N;

    for (int i = 0; i < N;i++){
        int key;
        cin>>key;

        if (key != 1)
            won++;

    }

    cout<<won;
}