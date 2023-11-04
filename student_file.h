#include <vector>
#include <queue>
using namespace std;

vector<int> Torneo(vector<int> habilidades, int n, int k) {
    queue<int> queue;

    for (int i = 2; i < habilidades.size(); i++) {
        queue.push(habilidades[i]);
    }

    int gamesWon = 0;
    int playerActual = habilidades[0];
    int playerDesafiante = habilidades[1];

    vector<int> output(2);

    for (int game = 1; game <= k; game++) {
        if (playerActual > playerDesafiante) {
            gamesWon++;
            output = { playerDesafiante, playerActual };
            queue.push(playerDesafiante);
        } else {
            gamesWon = 1;
            output = { playerActual, playerDesafiante };
            queue.push(playerActual);
            playerActual = playerDesafiante;
        }
        if (gamesWon == n) {
            queue.push(playerActual);
            playerActual = queue.front();
            queue.pop();
            gamesWon = 0;
        }
        playerDesafiante = queue.front();
        queue.pop();
    }

    return output;
}



