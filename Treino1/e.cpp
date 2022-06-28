    #include <iostream>

    using namespace std;

    #define max 10

    int main(){
        int N; cin>>N;

        bool map[max+1][max+1] = {false};
        bool result = true;

        for (int i = 0; i < N; i++){ //  reads bathership lines
            bool D;
            int L,R,C;
            cin>>D; // D = false => horizontally

            cin>>L;
            cin>>R;
            cin>>C;

            if (result)
            if (!D){ // (R,C)…(R,C+L−1) // horizontally
                for (int k = C; k < (C+L); k++)
                    if (((k > max) || (C > max)) || (map[R][k])){
                        result = false;
                        break;
                    } else 
                        map[R][k] = true;            
            } else //(R,C)…(R+L−1,C) // vertical
                for (int k = R; k < R+L; k++){
                    if (((k > max) || (C > max)) || (map[k][C])){
                        result = false;
                        break; 
                    } else
                        map[k][C] = true;
            } 
        }

        if (result)
            cout<<"Y";
        else
            cout<<"N";

    }