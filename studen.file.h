#include <vector>
using namespace std;

vector<int> Torneo(vector<int> habilidades, int N, int K) {
    vector<int> table;
    vector<int> queue;
    
    for (int i = 0; i < K; i++) {
        int player1 = habilidades[0];
        int player2 = habilidades[1];
        
        if (player1 > player2) {
            table.push_back(player1);
            queue.push_back(player2);
        } else {
            table.push_back(player2);
            queue.push_back(player1);
        }
        
        habilidades.erase(habilidades.begin());
        habilidades.erase(habilidades.begin());
        
        if (table.size() == 2) {
            if (table[0] == table[1]) {
                table.clear();
            } else {
                table.push_back(table[1]);
                table.pop_back();
            }
        }
        
        if (table.size() == 1 && N > 1) {
            table.push_back(queue[0]);
            queue.erase(queue.begin());
            N--;
        }
        
        if (table.size() == 2) {
            table.clear();
        }
    }
    
    vector<int> result;
    result.push_back(table[0]);
    result.push_back(table[1]);
    
    return result;
}
