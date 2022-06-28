#include <bits/stdc++.h>

using namespace std;

int Getface(string s){
  /*  switch (s){
        case "Tetrahedron": return 4;
        case "Cube": return 6  ;
        case "Octahedron": return 8;
        case "Dodecahedron": return 12;
        case "Icosahedron": return 20;
        default: return 0;
    }
    */
    if (s == "Tetrahedron") return 4; else
    if (s == "Cube") return 6; else
    if (s == "Octahedron") return 8; else
    if (s == "Dodecahedron") return 12; else
    if (s == "Icosahedron") return 20; else 
    return 0;
    
}

int main(){
    int n; cin>>n;
    int faces = 0;

    while (n--){
        string s;cin>>s;
        faces+=Getface(s);
    }

    cout<<faces<<"\n";

}