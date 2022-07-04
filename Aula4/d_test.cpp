#include <bits/stdc++.h>

using namespace std;


int main(){
    priority_queue<int> fila;

    for (int i = 0; i < 10; i++)
        fila.push(10);

    for (int i = 0; i < 10; i++)
        fila.push(2);

    for (int i = 0; i < 30; i++)
        fila.push(500);
    
    while (!fila.empty())
        cout<<"\n "<<fila.top(), fila.pop();
    

}