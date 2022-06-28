#include <iostream>

using namespace std;

int main(){
    int T; cin>> T;
    int points = 100;
    int max_points = 100;

 
    for (int i = 0; i < T ; i++){
        int value; cin >>value;
        points += value;
        if (points  > max_points)
            max_points = points;
        
    }
    cout<<max_points<<endl;
    
}