#include <bits/stdc++.h>

using namespace std;
#define len 500+1

int m[len][len];
int ymax,xmax,q;
int points[len];
int point[2] = {0,-1}; // 0 - point, 1 - line


int CalcMax(int y){
    int max = 0;
    //for (int y = 0; y < ymax; y++){
        int aux = 0;

        for (int x = 0; x < xmax; x++){
            if (m[y][x] == 1){
                aux++;
            } else { // = 0
                    if (aux > max)
                            max = aux;
                    aux = 0;
                }
        }
        if (aux > max)
            max = aux;
    //}
    return max;
}

void GetBestPoint(){
    point[0] = 0;
    point[1] = -1;
    for (int y = 0; y < ymax;y++)
        if (points[y] > point[0]){
            point[0] = points[y];
            point[1] = y;
        }
}



int main(){
    cin>>ymax>>xmax>>q;
    // n  5.10²  grid lines
    // m  5.10²  grid collums
    // q  5.10³  

    for (int y = 0; y < ymax; y++){
        for (int x = 0; x < xmax; x++)
            cin>>m[y][x];
        points[y] = CalcMax(y);

        if (points[y] > point[0]){
            point[0] = points[y];
            point[1] = y;
        }
    } 
    
    
    // 0 boca, 1 olhos    
    for (int w = 0; w < q; w++){
        int x,y;
        cin>>y>>x;
        x--;y--;
        m[y][x] = !m[y][x];
        points[y] = CalcMax(y);
        
        if (points[y] > point[0]){
            point[0] = points[y];
            point[1] = y;
        } else 
            if (point[1] == y)
                GetBestPoint();
    
        cout<<point[0]<<"\n";
        
        /*
        cout<<"\n\n";
        for (int y = 0; y < ymax; y++){
            for (int x = 0; x < xmax; x++)
                cout<<" "<<m[y][x];
            
            cout<<"\n";
        }
        */
    }     

}