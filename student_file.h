#include <vector>
#include <queue>

using namespace std;
vector<int> Torneo(vector<int> habilidades, int N, int K) {
    queue<int> lineup;
    for (size_t i = 2; i < habilidades.size(); ++i) {
        lineup.push(habilidades[i]);
    }

    int gamesWin = 0;
    int playerActual = habilidades[0];
    int playerDesafiante = habilidades[1];


    vector<int> resul(2);
    for (int juego = 1; juego <= K; ++juego) {
        if (playerActual > jugadorDesafiante) {
            gamesWin++;
            resul = {playerDesafiante, playerActual};
            lineup.push(playerDesafiante);
        } else {
            gamesWin = 1;
            resul = {playerActual, playerDesafiante};
            lineup.push(playerActual);
            playerActual = playerDesafiante;
        }

        if (gamesWin == N) {
            lineup.push(playerActual);
            playerActualActual = lineup.front();
            lineup.pop();
            gamesWin = 0;
        }

        playerDesafiante = lineup.front(); 
        lineup.pop();
    }
    
    return resul;
}



