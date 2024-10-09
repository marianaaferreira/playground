#include <iostream>
#define TMAX 3
using namespace std;

void mostraMatriz(int n, char m[][TMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "|" << m[i][j] << "|";
        }
        cout << endl;
    }
}

void escolhePosicao(int n, char posicao, char jogador, char m[][TMAX]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == posicao)
                m[i][j] = jogador;
        }
    }
}

char verificaVencedor(int n, char m[][TMAX]) {
    // Verifica linhas e colunas
    for (int i = 0; i < n; i++) {
        // Verifica linhas
        if (m[i][0] == m[i][1] && m[i][1] == m[i][2]) {
            return m[i][0];
        }
        // Verifica colunas
        if (m[0][i] == m[1][i] && m[1][i] == m[2][i]) {
            return m[0][i];
        }
    }

    // Verifica diagonais
    if (m[0][0] == m[1][1] && m[1][1] == m[2][2]) {
        return m[0][0];
    }
    if (m[0][2] == m[1][1] && m[1][1] == m[2][0]) {
        return m[0][2];
    }

    return 'f'; // Nenhum vencedor
}

char escolheJogador(char jogador) {
    return jogador == 'x' ? 'o' : 'x';
}

int main() {
    int n = 3;
    char m[TMAX][TMAX] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9' } };
    char jogador = 'x', posicao;
    bool finalizar = false;

    do {
        mostraMatriz(n, m);
        jogador = escolheJogador(jogador);
        cout << "Em que posicao voce quer colocar o '" << jogador << "'? ";
        cin >> posicao;
        escolhePosicao(n, posicao, jogador, m);
        char v = verificaVencedor(n, m);
        if (v == 'o' || v == 'x') {
            mostraMatriz(n, m);
            cout << "Vencedor: " << v << endl;
            finalizar = true;
        }
    } while (!finalizar);

    return 0;
}
