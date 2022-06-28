#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Tgame{ 
    private:
        bool AWonOverB(int A, int B){ return ((A >= 10) || ((A - B >= 2) && (A >= 5))); };  // A game is won when a player reaches at least 5 points with a at least a 2 point difference from his opponent, or by reaching 10 points (whichever comes first);
    public:
        int point_players[2] = {0};
        int index_server = 0;

        bool IfLeftWin(){ return AWonOverB(point_players[0],point_players[1]);};
        bool IfRightWin(){ return AWonOverB(point_players[1],point_players[0]);};
        int WhoWon(){
            if (IfLeftWin())  return 0;
            if (IfRightWin()) return 1;
            return -1;
        }
   
        void ComputePoint(char key){ 
            if (key == 'S')
                point_players[index_server]++;
            else { // R
                index_server = !index_server; // ponto de quem não é servidor
                point_players[index_server]++;
            }
        }

        void print(int pl,int pr, int won){  
            if (won == -1){ // n terminou a partida
                string star[2] = {""};
                star[index_server] = '*';
                cout<<pl<<" ("<<  point_players[0]   <<star[0]<<") - "<<pr<<" ("<<point_players[1]<<star[1]<<")\n";
            } else {
                string winner[2] = {""};
                winner[won] = " (winner)";
                cout<<pl<<winner[0]<<" - "<<pr<<winner[1]<<"\n";
            }
        }
};

bool IsWin(int value){return value >= 2;}
  
int main(){
    Tgame game;
    int point_players[2] = {0};

    char key;
    bool fim = false;

    while (key = getchar()){
        int won = 0;
        switch(key){
            case '\n':
            case '\0':
                    fim = true;
                    break;
            case 'R':
            case 'S':
                    game.ComputePoint(key);  
                    won = game.WhoWon(); 
                    if ( won != -1){
                        point_players[won]++;
                        game.point_players[0] = 0;
                        game.point_players[1] = 0;
                    }  
                    break;
            case 'Q': 
                won = -1;
                if (IsWin(point_players[0])) won = 0;
                if (IsWin(point_players[1])) won = 1;
                game.print(point_players[0],point_players[1],won);
                break;
        }
        if (fim)  break;
    }
}