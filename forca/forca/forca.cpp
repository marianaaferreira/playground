#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <ctime>
using namespace std;

int main() {
    int indice, tentativas = 3, j=6;
    bool acertou = 0, resp;
    char letra;
    string chute;
    vector<char> palavracript;
    vector<string> palavras = {
        "torta",
        "crepusculo",
        "efemero",
        "labirinto",
        "quimera",
        "horizonte",
        "nostalgia",
        "finito",
        "abobora",
        "vertigem",
        "aurora",
        "paradoxo",
        "melancolia",
        "sussurro"
    };

    srand(time(0));
    indice = rand() % palavras.size();

    cout << "Advinhe a seguinte palavra:" << endl;
    for (int i = 0; i < palavras.at(indice).size(); i++) {
        cout << "* ";
    }
    cout << endl;

    for (int i = 0; i < palavras.at(indice).size(); i++)
        palavracript.push_back('*');

    while (not acertou and tentativas > 0 and j>0) {
        cout << "Diga uma letra (Voce tem mais " << j << " tentaivas:"; j--;
        cin >> letra;
        cin.ignore(); 

        for (int i = 0; i < palavras.at(indice).size(); i++) {
            if (palavras.at(indice)[i] == letra) {
                palavracript[i] = letra;  
            }
        }

        for (const auto& caractere : palavracript)
            cout << caractere << " ";
        cout << endl;

        acertou = 1;
        for (const auto& caractere : palavracript)
            if (caractere == '*') acertou = 0;
      
        if (not acertou) {
            cout << "Deseja dar algum palpite? (Voce tem apenas " << tentativas << " tentativa(s) restantes) Sim[1] Nao [0]" << endl;
            cin >> resp;
            cin.ignore();

            if (resp) {
                cout << "Digite seu palpite: ";
                getline(cin, chute);
                tentativas--;
                if (chute == palavras.at(indice)) {
                    cout << "Parabens, voce acertou!!!" << endl;
                    acertou = true;
                }
                else {
                    cout << "Palpite incorreto." << endl;
                }
            }
        }
    }

    if (!acertou) {
        cout << "Suas tentativas acabaram! A palavra correta era: " << palavras.at(indice) << endl;
    }

    return 0;
}
