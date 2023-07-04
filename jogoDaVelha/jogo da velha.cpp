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
    for (int i = 0; i < n;i++) {
        for (int j = 0; j < n; j++) {
            if (m[i][j] == posicao)
                m[i][j] = jogador;
        }
    }
}

//a funcao conta quando o valor nao eh numerico entao mesmo que uma fileira esteja oox ele considera que tem um vencedor
//arrumar
char verificaVencedor(int n, char m[][TMAX]) {
    int cont1=0, cont2 = 0;

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++) {
            if (i == 0 or j == 0) {
                if (not isdigit(m[i][j]))
                    for (int k = 0; k < 3; k++) {
                        if (m[i][k] == m[i][j])
                            cont1++;
                        if (m[k][j] == m[i][j])
                            cont2++;
                    }
                if (cont1 == 3 or cont2 == 3) {
                    return m[i][j];
                }
            }
        }
    return 'f';

}

char escolheJogador(char jogador) {
    if (jogador == 'x')
        jogador = 'o';
    else
        jogador = 'x';
    return jogador;
}

int main(){
    int n = 3;
    char m[TMAX][TMAX] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9' } };
    char jogador = 'x', posicao;
    bool finalizar = false;
    do {
        mostraMatriz(n, m);
        jogador = escolheJogador(jogador);
        cout << "Em que posicao vc quer colocar o " << "'" << jogador << "'";
        cin.get(posicao);
        cin.ignore();
        escolhePosicao(n, posicao, jogador, m);
        char v = verificaVencedor(n, m);
        if (v == 'o' or v == 'x') {
            cout << "Vencedor: " << v;
            finalizar = true;
        }
    } while (not finalizar);
}

