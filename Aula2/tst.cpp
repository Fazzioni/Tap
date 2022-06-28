#include <bits/stdc++.h>

using namespace std;

int main(){

    int max = 200;
    char b[max];

    memset(b,'*',max);

    for (int i = 0; i < max; i++)
        cout<<"\n"<<b[i]<<": "<<b[i][1];

}
/*
9
30 50
0 20
20 40
40 60
60 80
10 30
50 70
70 90
80 0

 9 0 20 20 40 40 60 60 80 10 30 30 50 50 70 70 90 80 0

*/