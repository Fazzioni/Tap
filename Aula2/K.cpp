#include <bits/stdc++.h>

using namespace std;

#define brown 0
#define blue 1

int main(){
    int N;
    cin>>N;
    int colors[2] = {0,0};

    for (int w = 0; w < N; w++){
        int key;cin>>key;
        colors[key]++;
    }


    // 1 = blue
    // 0 = brown


    int turns = colors[blue];
    if (colors[brown] > 0)
        turns++;
    cout<<turns<<"\n";
    /*
    //while (colors[brown] != 0) || (colors[blue] != 0){

        if (colors[brown] != 0){ 
                // vamos aguardar brown - 1 turnos
                // e vai sair do jogo todos os marrons
            turns = colors[brown]-1;
            colors[brown] = 0;
        }

        if (colors[blue] != 0) {
            // se ele for azul, espera 2 turnos
            // se ninguem sair no segundo turno

            turns ++;
            // ninguem vai sair


        }

    //}


    //  1- azul
    // turno 1: azul sai
    // turno 2: todos os marrons saem

    // 2 azul, 1 marrom
    // turno 1: 
    //          azul: vê 1 marrom e 1 azul                
    //        marron: vê 2 azul
    // turno 2: 
    //      marrom vê os dois azuls e same
    //      marrom sai, pq se ninguem saiu no turno 1, ele é marrom
    // turno 3: os 2 azuis saem


    // 2 azul:
    // turno 1: cada azul vê 1 azul
    //          se tivesse 1 marrom, 1 dos azuis teriam saido
    //          
    // turno 2: os dois azuis saem


    // 2 azul, 2 marrom
    //turno 1: 
    //      azul: ve 2 marrom e 1 azul
    //      marrom: ve 2 azul e marrom
    //
    //turno 2: se 1 azul nao saiu no primeiro turno
    //      os 2 azul saem

    // 3 azul:
    //  turno 1:
    //          cada azul vê 2 azul
    //  turno 2:
    //         nenhum azul saiu
    //  turno 3: 


    // minimo de turnos = n_azul

    // se tiver marrom
    // turnos ++; marrons saem todos juntos


    // 1 marrom espera 1 partida
    // 1 azul e 1 marrom
    // se o azul n foi embora ele sabe que ele é marrom

    // 2 azul
    // espera 1

    */

}